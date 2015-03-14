<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if(empty($_POST["symbol"]))
        {
            apologize("You must enter the symbol of stock you want to buy");
        }
        else if(empty($_POST["shares"])||$_POST["shares"]<=0)
        {
            apologize("You must enter legitmate number of stocks to buy");
        }
        else
        {
        $b=query("SELECT cash FROM users where id = ?",$_SESSION["id"]);
        $s=lookup($_POST["symbol"]);
        if($b[0]["cash"]<$s["price"]*$_POST["shares"])
        {
            apologize("Dont forget your AAUKAT");
        } 
        else
        {
            $query = query("INSERT INTO portfolio(id, symbol, shares) VALUES (?, ?, ?)ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)",$_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"]);
            if ($query === false)
            {
                apologize("Error while buying shares.");
            }
            $b = query("UPDATE users SET cash = cash - ? where id = ?", $s["price"]*$_POST["shares"], $_SESSION["id"]);
            if ($b === false)
            {
                apologize("Error while buying shares.");
            }
            $b=query("INSERT INTO history (transaction, symbol, shares, price) VALUES('BUY', ?, ?, ?)", $_POST["symbol"], $_POST["shares"], $s["price"]);
            redirect("/");
        }
        }
    }
    else
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }
?>
    
