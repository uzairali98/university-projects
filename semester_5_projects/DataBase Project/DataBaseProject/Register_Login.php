<?php
 
 $connection_holder = mysqli_connect('localhost','root','root','playerstats');

 if(mysqli_connect_errno())
 {
 	die("cannot connect to database");
 } 

 $player_username = $_POST["name"];
 $player_xp;
 //echo "player name is ".$player_username;
 $Name_check_query = "SELECT Player_Name FROM player WHERE Player_Name='".$player_username."';";
 $query = mysqli_query($connection_holder,$Name_check_query) or die("name check query failed");

	 if(mysqli_num_rows($query) == 0)
	 {
	 	//echo "Player not found in Database.Now Inserting it in the Database";
	 	$insert_query = "INSERT INTO player (Player_Name) VALUES ('".$player_username."');";
	 	mysqli_query($connection_holder,$insert_query) or die("ERROR cannot insert player into table");
	 }
	
	 	//echo "Player found in the database. Reteriving values from DataBase";
	 	$get_query = "SELECT Player_XP FROM player WHERE Player_Name='".$player_username."';";
	 	$query = mysqli_query($connection_holder,$get_query) or die("get query failed");
	 	$getvar = mysqli_fetch_assoc($query);
	 	$player_xp = $getvar["Player_XP"];
	 	echo $player_xp;

 ?>
