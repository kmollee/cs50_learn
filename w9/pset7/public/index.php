<?php

    // configuration
    require("../includes/config.php");

    // get user portfolios, use session id
    $rows = query("SELECT symbol, shares FROM portfolios WHERE id =?", $_SESSION["id"]);

    // portfolios array
    $portfolios = [];

    if (count($rows) > 0)
    {
        // push all the query data to the array
        foreach ($rows as $key => $row)
        {
            // get the query symbol, and go lookup, find out what price currently
            $stock = lookup($row["symbol"]);
            // check is it get successful?
            if($stock !== false)
            {
                $portfolios[] = [
                    "name" => $stock["name"],
                    "price" => number_format($stock["price"], 2, '.', ''),
                    "shares" => number_format($row["shares"], 2, '.', ''),
                    "symbol" => $row["symbol"],
                    "value" => number_format($row["shares"]*$stock["price"], 2, '.', '')
                ];
            }

        }

    }

    $rows = query("SELECT cash FROM users WHERE id =?", $_SESSION["id"]);

    $cash = number_format($rows[0]["cash"], 2, '.', '');

    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "portfolios" => $portfolios, "cash" => $cash]);

?>
