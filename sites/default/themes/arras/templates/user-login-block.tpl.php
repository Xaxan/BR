<style>
.btn {
-webkit-border-radius: 4;
-moz-border-radius: 4;
border-radius: 4px;
font-family: Arial;
color: #ffffff!important;
font-size: 12px;
background: #8E0000;
padding: 5px 12px 6px 11px;
text-decoration: none;
margin-top: 21px;
font-weight: bold;
}

.btn:hover {
  background: #450505;
  text-decoration: none;
}
</style>
<div id="user-login-block-container">
  <div id="user-login-block-form-fields">
    <?php print $name; // Display username field ?>
    <?php print $pass; // Display Password field ?>
    <?php print $submit; // Display submit button ?>
    <?php print $rendered; // Display hidden elements (required for successful login) ?> 
  </div>
  <div style="color:rgb(104, 0, 0);font-weight: bold;text-align: center;font-size: 10px;">
  <span>Subscribe for week Membership and receive full access to Member's Exclulsive Picks and Card&Corner (NonVIP) Picks!</span>
  </div>
   <div style="text-align: center;margin-top: 8px;">
      <a href="/aMember/signup" class="btn" target="_blank">Create new account</a>
  </div>
</div>