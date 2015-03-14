<?php
    
    require("../includes/config.php");    
    
    //if GET request is made
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $positions= query("SELECT transaction, symbol, shares, price FROM history");
        
        // else render form
        render("history_form.php", ["title" => "History", "positions" => $positions]);
    }
    
?>
