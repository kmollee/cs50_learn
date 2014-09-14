<div>
    <table class="table table-striped">
        <thead>
            <tr>
                <th>Transaction</th>
                <th>Date/Time</th>
                <th>Symbol</th>
                <th>Shares</th>
                <th>Price</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($history as $h): ?>
                <tr>
                    <td><?= $h["action"] ?></td>
                    <td><?= date('Y-m-d H:i:s', strtotime($h["date"])) ?></td>
                    <td><?= $h["symbol"] ?></td>
                    <td><?= $h["share"] ?></td>
                    <td>$<?= $h["price"] ?></td>
                </tr>
            <?php endforeach ?>
        </tbody>
    </table>
</div>
