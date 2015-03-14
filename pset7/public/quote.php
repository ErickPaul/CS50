<?php

    // configuration
    require("../includes/config.php");
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        if (empty($_POST["symbol"]))
        {
            apologize("Please enter the stock symbol.");
        }
        $s=lookup($_POST["symbol"]);
        if ($s===FALSE)
        {
            // TODO
            apologize("invalid symbol");
        }
        else
        {
            render("quote.php", ["title" => "Quote","symbol" => $s["symbol"],"price" => $s["price"],"name" => $s["name"]]);
        }
    }
    else
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }
?>
