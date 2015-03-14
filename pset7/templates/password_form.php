<form action="password.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autofocus class="form-control" name="oldpassword" placeholder="Old Password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="newpassword" placeholder="New Password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="confirmation" placeholder="Confirmation" type="password"/>
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Change</button>
        </div>
    </fieldset>
</form>
<div>
    or <a href="logout.php">log out</a>
</div>
