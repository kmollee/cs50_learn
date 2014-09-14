<ul class="nav nav-pills">

    <?php
        if(!empty($_SESSION["id"])){
            echo "<li><a href='index.php'>Home</a></li>";
            echo "<li><a href='quote.php'>Quote</a></li>";
            echo "<li><a href='deposit.php'>Deposit</a></li>";
            echo "<li><a href='buy.php'>Buy</a></li>";
            echo "<li><a href='sell.php'>Sell</a></li>";
            echo "<li><a href='history.php'>History</a></li>";
            echo "<li><a href='change_password.php'>Change Password</a></li>";
            echo "<li><a href='logout.php'><strong>Logout</strong></a></li>";
        }
    ?>
</ul>
