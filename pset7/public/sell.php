<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if($_POST["stock"]=="")
        {
            apologize("You must select a stock symbol to sale");
        }
        else
        {
            $position=query("SELECT shares FROM portfolio WHERE id=? AND symbol= ?",$_SESSION["id"],$_POST["stock"]);
            $a=query("DELETE FROM portfolio WHERE id = ? AND symbol = ?",$_SESSION["id"],$_POST["stock"]);
            $s=lookup($_POST["stock"]);
            $a=query("UPDATE users SET cash = cash + ? WHERE id = ?",$position[0]["shares"]*$s["price"],$_SESSION["id"]);
            $ayush="SELL";
            $b=query("INSERT INTO history (transaction, symbol, shares, price) VALUES('SELL', ?, ?, ?)", $_POST["stock"], $position[0]["shares"], $s["price"]);
            redirect("/");
        }
    }
    else
    {
        // else render form
        render("sell_form.php", ["title" => "Sell"]);
    }
?>    
