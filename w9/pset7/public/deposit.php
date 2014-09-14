<?php
    // configuration
    require("../includes/config.php");
    // if check method is POST?
    if ($_SERVER["REQUEST_METHOD"] == "POST"){
        // if input(deposit) is not empty and is a valid number?
        if(!empty($_POST["deposit"]) && is_numeric($_POST["deposit"]))
        {
            // try update user's cash from sql users table
            $rows = query("UPDATE users SET cash = cash + ? WHERE id = ?",
                $_POST["deposit"], $_SESSION["id"]);
            // if fail redirect 500 page
            if ($rows === false) {
                appology("can't update user cash");
            }
            // try log operation into history
            // Log the history
            // type 1 is buy 0 is sell
            $query = query("INSERT INTO history(id, symbol, share, price, type) VALUES (?, ?, ?, ?, ?)"
            ,$_SESSION["id"], '', 0, $_POST["deposit"], 2);
            if ($query === false) {
                apologize("Log error.");
            }
            // render deposit_form with deposit variable
            redirect("/w9/pset7/public/");
        }
        // else
        else
        {
            //appology
            appology("deposit have to been not empty and a valid number.");
        }
    }
    // else render template deposit_form
    else{
        render("deposit_form.php", ["title"=>"Deposit"]);
    }
?>
