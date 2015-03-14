<!DOCTYPE html>
<html>
<head>
<style>

th, td {
    padding: 5px;
}
th, ul {
    text-align:center
}
</style>
</head>

<body>

<ul class="nav nav-pills">
    <li><a href="quote.php">Quote</a></li>
    <li><a href="buy.php">Buy</a></li>
    <li><a href="sell.php">Sell</a></li>
    <li><a href="history.php">History</a></li>
    <li><a href="password.php">CHANGE PASSWORD</a></li>
    <li><a href="logout.php"><strong>Log Out</strong></a></li>
</ul>

<br>

<table class="table table-striped" style="width:100%">
    <tr>
        <th>SYMBOL</th>
        <th>NAME</th>
        <th>SHARES</th>
        <th>PRICE</th>
        <th>TOTAL</th>
    </tr>    
    <?php $positions=query("SELECT symbol,shares FROM portfolio WHERE id=?",$id);
          $b=0;
          $a=query("SELECT cash FROM users WHERE id=?",$id);?>
    <?php foreach ($positions as $position): ?>
    <?php $s=lookup($position["symbol"]); ?>
    <tr>
        <td><?= $position["symbol"] ?></td>
        <td><?= $s["name"] ?></td>
        <td><?= $position["shares"] ?></td>
        <td><?= $s["price"] ?></td>
        <?php $b+=$position["shares"]*$s["price"] ?>
        <td>$ <?= $position["shares"]*$s["price"] ?></td>
        
    </tr>
    
    <?php endforeach ?>
    <tr>
        <th>CASH</th>
        <td> </td>
        <td> </td>
        <td> </td>
        <th> $<?= $a[0]["cash"] ?> </th>
    </tr>
</table>

</body>
</html>
    

