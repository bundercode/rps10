<?php
$stat_file = "status.txt";
$stat_hand = fopen($stat_file, 'r');
#$light_stat = $_POST["light_stat"];
$light_stat = fgets($stat_hand);
#$pump_stat = $_POST["pump_stat"];
$pump_stat = fgets($stat_hand);
fclose($stat_hand);
?>
<html>
<head>
	<title>Green River</title>
	<link href="style.css" type="text/css" rel="stylesheet" />
</head>
<body>
	<div id="body_div">
		<h1 id="heading" align="center">Green River</h1>
		<form method="post" action="<?php `sudo ./toggle.sh`; ?>">
			<p><button id="light" type="submit" name="light_stat" value="light"><?php echo $light_stat; ?></button></p>
			<p><button id="pump" type="submit" name="pump_stat" value="pump"><?php echo $pump_stat; ?></button></p>
		</form>
	</div>
</body>
</html>
