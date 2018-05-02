<?php

define("server", "localhost:3306");
define("uname", "root");
define("pwd", "abcde123");
define("db", "prac");

$connection = mysqli_connect($server, $uname, $pwd, $db);
session_start();

if (isset($_POST['submit'])) {
	$username = mysqli_real_escape_string($db, $_POST['username']);
	$password = mysqli_real_escape_string($db, $_POST['password']);
	
	$sql = "SELECT * from xyz where username='$username' and password='$password'";
	
	$result = mysqli_query($sql);
	
	$count = mysqli_num_rows($result);

	if($count == 1) {
         session_register("username");
         session_register("password");
         
         echo "WELCOME";
      }else {
         echo "Your Login Name or Password is invalid";
      }
}
?>

<html>
<head>
	<title></title>
</head>
<body>

<form method="POST">
	<label for"username">Username</label>
	<input type="text" name="username" required>
	
	<label for"password">Password</label>
	<input type="password" name="password" required>
	
	<button type="submit" name="submit">Login</button>
</form>

</body>
</html>
