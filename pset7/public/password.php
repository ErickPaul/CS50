<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        $rows = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        $row = $rows[0];
        if (empty($_POST["oldpassword"]))
        {
            apologize("You must provide your old password.");
        }
        else if(crypt($_POST["oldpassword"], $row["hash"]) != $row["hash"])
        {
            apologize("Old Password did not match.");
        }
        else if (empty($_POST["newpassword"]))
        {
            apologize("You must provide your new password.");
        }
        else if (empty($_POST["confirmation"]))
        {
            apologize("You must provide your confirmation password.");
        }
        else if($_POST["newpassword"]!=$_POST["confirmation"])
        {
            apologize("new password and its confirmation does not match.");
        }
        else
        {
            $result=query("INSERT INTO users ( hash ) VALUES( ? )", crypt($_POST["newpassword"]));
            if($result===FALSE)
            {
                apologize("an error occured");
            }
            else
            {
                redirect("index.php");
            }
            
        }
    }
    else
    {
        // else render form
        render("password_form.php", ["title" => "Password"]);
    }

?>
