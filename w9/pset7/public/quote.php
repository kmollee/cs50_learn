<?php

    // configuration
    require("../includes/config.php");

    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check submit
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide symbol.");
        }

        // get stock
        $stock = lookup($_POST["symbol"]);

        // check stock is found, if fail to found will return false
        if($stock === false){
            apologize("You must provide correct symbol.");
        }
        else
        {
            $symbol = $stock["symbol"];
            $name = $stock["name"];
            $price = number_format($stock["price"], 2, '.', '');
            render("quote_result.php", ["title" => "Quote", "symbol" => $symbol, "name" => $name, "price" => $price]);
        }

        // if all is ok, redirect to show page
    }
    else
    {
        // render form
        render("quote_form.php", ["title" => "Get Quote"]);
    }

?>
