<?php
    //Distance ophalen van arduino
    $distance=$_POST["distance"];

    //Diepte brievenbus in cm.
    $brievenbus = 10;

    //Zodra de doorgegeven afstand kleiner is dan de diepte van
    //de brievenbus komt er een melding.
    if(distance < $brievenbus)
    {
        <script type=javascript>
          alert("Bedankt voor de post.");
        </script>
    }
?>
