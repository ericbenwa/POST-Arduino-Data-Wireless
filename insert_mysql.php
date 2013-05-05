<?php

foreach ($_REQUEST as $key => $value)
{
	if ($key == "yourdata") {
		$yourdata = $value;
	}
}

// EDIT: Your mysql database account information
$username = "test_user";
$password = "test_password";
$database = "test_db_name_here";
$tablename = "test_table_name_here";
$localhost = "localhost";

// Check Connection to Database
if (mysql_connect($localhost, $username, $password))
  {
  	@mysql_select_db($database) or die ("Unable to select database");

    // Next two lines will write into your table 'test_table_name_here' with 'yourdata' value from the arduino and will timestamp that data using 'now()'
    $query = "INSERT INTO $tablename VALUES ($yourdata,now())";
  	$result = mysql_query($query);
  } else {
  	echo('Unable to connect to database.');
  }

?>