<?php
    // configuration
    require("../includes/config.php");
    // if post
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check submit symbol and shares
        if(empty($_POST["symbol"]))
        {
            apologize("You must provide symbol.");
        }
        if (empty($_POST["shares"]) || !is_numeric($_POST["shares"]) || !preg_match("/^\d+$/", $_POST["shares"]))
        {
            apologize("You must provide correct shares.");
        }


        // also check symbol is real
        $stock = lookup($_POST["symbol"]);
        if ($stock === false) {
            apologize("Enter symbol is not real.");
        }

        // calculate value
        $value = $stock["price"] * $_POST["shares"];

        // check user have enough cash to buy
        $rows = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        if ($rows !== false) {
            if (count($rows) == 1) {
                $cash = $rows[0]["cash"];
                if ($cash < $value) {
                    apologize("You don't have enough money to buy.");
                }
            }
            else{
                apologize("Select user error.");
            }
        }
        else{
            apologize("Select user error.");
        }

        // Insert the bought stock into database
        $query = query("INSERT INTO portfolios(id, symbol, shares) VALUES (?, ?, ?)
        ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)"
        ,$_SESSION["id"], strtoupper($stock["symbol"]), $_POST["shares"]);
        if ($query === false)
        {
            apologize("Error while buying shares.");
        }
        /*
        // check portfolios have relationship exist
        $rows = query("SELECT shares FROM portfolios WHERE id = ? and symbol = ?", $_SESSION["id"], strtoupper($_POST["symbol"]));
        //$rows = query("SELECT shares FROM portfolios WHERE id = ? AND symbol = ?", $_SESSION["id"], strtoupper($_POST["symbol"]));
        // if not exist, then insert
        if ($rows === false) {
            apologize("select portfolios error.");
        }
        else if (count($rows) == 0)
        {
            $query = query("INSERT INTO portfolios (id, symbol, shares) VALUE(?, ?, ?)",
                $_SESSION["id"], $_POST["symbol"], $_POST["shares"]);
            if($query === false)
            {
                apologize("inserting portfolios error.");
            }
        }
        // if exist, then update
        else{
            $query = query("UPDATE portfolios SET shares = shares + ? WHERE id = ? AND symbol = ?",
                $_POST["shares"], $_SESSION["id"], strtoupper($_POST["symbol"]));
            if($query === false)
            {
                apologize("updating portfolios error.");
            }
        }
        */

        // update user cash
        $rows = query("UPDATE users SET cash = cash - ?  WHERE id = ?", $value, $_SESSION["id"]);
        if ($rows === false) {
            apologize("updating user cash error.");
        }

        // Log the history
        // type 1 is buy 0 is sell
        $query = query("INSERT INTO history(id, symbol, share, price, type) VALUES (?, ?, ?, ?, ?)"
        ,$_SESSION["id"], strtoupper($stock["symbol"]), $_POST["shares"], $stock["price"], 1);
        if ($query === false) {
            apologize("Log error.");
        }
        // redirect to home page
        redirect("/w9/pset7/public/index.php");

    }
    // else render form
    else
    {
        render("buy_form.php", ["title" => "Buy"]);
    }


?>
