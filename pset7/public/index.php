<?php

    // configuration
    require("../includes/config.php"); 

    // render portfolio
    render("portfolio.php", ["title" => "Portfolio","id"=>$_SESSION["id"]]);

?>
