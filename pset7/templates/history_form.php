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

<br>

<table class="table table-striped" style="width:100%">
   
    <tr>
        <th>TRANSACTION</th>
        <th>SYMBOL</th>
        <th>SHARES</th>
        <th>PRICE</th>
    </tr>    
    
    <?php foreach ($positions as $position): ?>
    <tr>
    
        <td><?= $position["transaction"] ?></td>
        <td><?= $position["symbol"] ?></td>
        <td><?= $position["shares"] ?></td>
        <td><?= $position["price"] ?></td>
        
    </tr>
    
    <?php endforeach ?>
    
</table>

</body>
</html>
    

