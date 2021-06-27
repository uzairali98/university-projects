<?php
 
 $connection_holder = mysqli_connect('localhost','root','root','playerstats');

 if(mysqli_connect_errno())
 {
 	die("cannot connect to database");
 } 

 $player_username = $_POST["name"];
 $player_xp = $_POST["xp"];
  //echo "player name is ".$player_username;
 $Get_Player_Xp_query = "SELECT Player_XP FROM player WHERE Player_Name='".$player_username."';";
 $query = mysqli_query($connection_holder,$Get_Player_Xp_query) or die("Get_Player_Xp_query query failed");

	 if(mysqli_num_rows($query) != 0)
	 {
	 	$update_query = "UPDATE player SET Player_XP = ' $player_xp ' WHERE Player_Name ='$player_username';";
	 	mysqli_query($connection_holder,$update_query) or die("ERROR cannot update player score into the table");
	 	echo "player data saved sucessfully";
	 }
	 else
	 {
	 	echo "player not found";
	 }
	 
 ?>
