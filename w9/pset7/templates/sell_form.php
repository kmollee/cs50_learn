<?php if(count($symbols) > 0): ?>
    <form action="sell.php" method="post">
        <fieldset>
            <div class="form-group">
                <select class="form-control" name="symbol">
                    <?php
                        foreach($symbols as $symbol)
                        {
                            print("<option value='{$symbol["symbol"]}'>{$symbol["symbol"]}</option>\n");
                        }
                    ?>
                </select>
            </div>
            <div class="form-group">
                <button type="submit" class="btn btn-default">Sell!</button>
            </div>
        </fieldset>
    </form>
<?php else: ?>
    <p>currently, nothing can be sell</p>
<?php endif ?>
