<form action="sell.php" method="post"> 
    <fieldset>
        <div class="form-group">
            <select name="stock">
                <option value=""></option>
                <?php $positions=query("SELECT symbol,shares FROM portfolio WHERE id=?",$_SESSION["id"]);?>
                <?php foreach ($positions as $position): ?>
                <?php $r=$position["symbol"] ?>
                <option value="<?=$r?>"><?=$r?></option>
                <?php endforeach ?>
            </select>        
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Sell</button>
        </div>
    </fieldset>
</form>    
