<?php
$hostname = "localhost";
$username = "root";
$password = "";
$database = "sensor_readings";

$conn = mysqli_connect($hostname, $username, $password, $database);

if(!$conn){
    die("Connection failed: " . mysqli_connect_error());
}

echo "Databased";

if(isset($_POST["temperature"]) && isset($_POST["humidity"])){

$t = $_POST["temperature"];
$h = $_POST["humidity"];

$sql = "INSERT INTO da (Temperature, Humidity) VALUES (".$t.", ".$h.")";

if (mysqli_query($conn, $sql)){
    echo "<br> New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $mysqli_query_error($conn);
}

}
?>
