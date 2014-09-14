<?php

    // configuration
    require("../includes/config.php");

    // if form was submit
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        else if ($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Password doesn't math confirmation.");
        }

        // try insert username and password to usertable
        $rows = query("INSERT INTO users (username, hash, cash) VALUE(?, ?, 1000.00)",
            $_POST["username"], crypt($_POST["password"]));

        // if insert fail will return false
        if($rows === false)
        {
            apologize("Username already exist.");
        }
        // insert ok
        else
        {
            // get last insert id
            $rows = query("SELECT LAST_INSERT_ID() AS id");
            // check get the row amount is one
            if (count($rows) == 1)
            {
                // get id
                $id = $rows[0]["id"];
                // set in session
                $_SESSION["id"] = $id;
                // redirect page
                redirect("/w9/pset7/public/index.php");
            }
        }
    }
    else
    {
        // render form
        render("register_form.php", ["title" => "Register"]);
    }

?>
