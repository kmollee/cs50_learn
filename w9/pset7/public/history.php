<?php

    // configuration
    require("../includes/config.php");

    // get
    //$cash = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    //$rows = query("SELECT CASE WHEN type = 0 THEN 'SELL' ELSE 'BUY' END action, symbol, shares, date FROM history WHERE id = ? order by date desc", $_SESSION["id"]);
    $rows = query("SELECT CASE WHEN type = 0 THEN 'SELL' WHEN type = 2 THEN 'DEPOSIT' ELSE 'BUY' END action, symbol, share, price, date FROM history
    WHERE id = ? order by date desc", $_SESSION["id"]);
    if($rows === false)
    {
        apologize("get history error.");
    }
    if(count($rows) == 0)
    {
        apologize("no record transactions for user.");
    }

    render("history_result.php", ["title"=>"History", "history"=>$rows]);

?>
