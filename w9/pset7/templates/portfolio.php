<!--
<div>
    <img alt="Under Construction" src="/w9/pset7/public/img/construction.gif"/>
</div>
-->
<div>
    <?php if(!empty($portfolios)): ?>
        <table class="table table-striped">
            <thead>
                <tr>
                    <th>Symbol</th>
                    <th>Name</th>
                    <th>Shares</th>
                    <th>Price</th>
                    <th>Total</th>
                </tr>
            </thead>
            <tbody>
                <?php foreach ($portfolios as $p): ?>
                    <tr>
                        <td><?= $p["symbol"] ?></td>
                        <td><?= $p["name"] ?></td>
                        <td><?= $p["shares"] ?></td>
                        <td>$<?= $p["price"] ?></td>
                        <td>$<?= $p["value"] ?></td>
                    </tr>
                <?php endforeach ?>
                <tr>
                    <td>CASH</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>$<?= $cash ?></td>
                </tr>
            </tbody>
        </table>
    <?php else: ?>
        <p> currently, no data</p>
    <?php endif ?>
</div>
