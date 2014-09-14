<?php
    require("../includes/config.php");

    // check method
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check 3 input(origin_password, new_password, confirm_password)
        // check is empty or unmatch
        if(empty($_POST["origin_password"]) || empty($_POST["new_password"]) || empty($_POST["confirm_password"])
            || $_POST["new_password"] != $_POST["confirm_password"])
        {
            apologize("You must provide origin password and new_password have to match cobfirm password.");
        }
        else
        {
            // crypt origin password compare user password
            // get password from sql
            $rows = query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
            // check the origin_password is right
            if($rows === false || count($rows)!=1)
            {
                apologize("Get user hash fail.");
            }
            else{
                $origin_password = $rows[0]["hash"];
            }
            // compare
            // if not match then apology
            if (crypt($_POST["origin_password"], $origin_password) == $origin_password)
            {
                // if match, update user new_password
                // need crypt
                // update user cash
                $rows = query("UPDATE users SET hash = ?  WHERE id = ?", crypt($_POST["new_password"]), $_SESSION["id"]);
                if ($rows === false) {
                    apologize("updating user password error.");
                }
                $_SESSION["id"] = '';
                redirect("/w9/pset7/public/index.php");

            }
            // also check the update is work?
            else
            {
                apologize("password is not match origin.");
            }
        }
    }
    // if is GET, return render template
    else
    {
        render("password_form.php", ["title"=>"Reset Password"]);
    }

?>
