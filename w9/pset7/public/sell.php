<?php

    // configuration
    require("../includes/config.php");



    // if method is post
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check submit
        if(empty($_POST["symbol"]))
        {
            apologize("You must provide symbol.");
        }
        // check symbol is real
        $stock = lookup($_POST["symbol"]);

        if ($stock === false)
        {
            apologize("Entered stock symbol was invalid.");
        }
        else
        {
            $rows = query("SELECT shares FROM portfolios WHERE id = ? and symbol = ?", $_SESSION["id"], strtoupper($_POST["symbol"]));

            // check query status
            if (count($rows) == 1) {
                $shares = $rows[0]["shares"];
            }
            else{
                apologize("Shares for specified symbol not found.");
            }
            // value is share multy stock price
            $value = $shares * $stock["price"];

            // delete specified symbol of user
            $query = query("DELETE FROM portfolios WHERE id = ? AND symbol = ?", $_SESSION["id"], strtoupper($_POST["symbol"]));
            // check status
            if ($query === false) {
                apologize("Error while selling shares.");
            }
            // update user cash
            $query = query("UPDATE users SET cash = cash + ? WHERE id = ?", $value, $_SESSION["id"]);
            // check status
            if ($query === false) {
                apologize("Error while updating cash.");
            }
            // Log the history
            // type 1 is buy 0 is sell
            $query = query("INSERT INTO history(id, symbol, share, price, type) VALUES (?, ?, ?, ?, ?)"
            ,$_SESSION["id"], strtoupper($stock["symbol"]), $shares, $stock["price"], 0);
            if ($query === false) {
                apologize("Log error.");
            }
            redirect("/w9/pset7/public/index.php");
        }

        //$rows = query("DELETE FROM portfolios WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);

    }
    else
    {
        // first need to query user current portfolios
        // get user portfolios, use session id
        $rows = query("SELECT symbol FROM portfolios WHERE id =?", $_SESSION["id"]);
        // render sell form
        render("sell_form.php", ["title"=>"Sell", "symbols"=>$rows]);
    }

?>
