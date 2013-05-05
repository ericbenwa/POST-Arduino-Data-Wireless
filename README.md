POST-Arduino-Data
=================

A simple way to send data from an Arduino and save it to a database (MySQL) over WiFi. 


Items You'll Need
-------------
Arduino (Uno or similar)<br />
Arduino WiFi Shield<br />
USB cable for Arduino<br />
<a href="https://github.com/ericbenwa/POST-Arduino-Data/archive/master.zip">


Getting Started
-------------

### Setup MySQL Database<br />
1. Create MySQL Database<br />
2. Create MySQL User<br />
3. Give newly created MySQL User access to your newly created MySQL Database<br />
4. Give newly created MySQL User full privileges to your newly created MySQL Database<br />
5. Create a table for your database<br />
6. Add 2 columns to your table: `yourdata`, `timestamp`<br />
7. For timestamp column, change the `type` to `DATETIME` and the index to `PRIMARY`<br />
<br />

### Edit INSERT script<br />
1. Download `insert_mysql.php`<br />
2. Edit the `$username`, `$password`, `$database`, and `$tablename` to match your setup<br />
3. Upload `insert_mysql.php` to your web-host (remember this URL for later)<br />
<br />

### POST Arduino data to MySQL Database<br />
1. Download arduino_post/arduino_post.ino<br />
2. Edit `yournetwork` (wireless network), `yourpassword` (wireless password) to connect to your router<br />
3. Edit www.yourdomain.com (for `char server[]`) to the domain you are hosting insert_mysql.php (not the full path to the file)<br />
4. Edit the POST url to match the path to `insert_mysql.php`<br />
5. Edit the Host: www.yourdomain.com to the domain you are hosting `insert_mysql.php` (not the full path to the file) 
6. Connect the Arduino WiFi shield to your Arduino<br />
7. Connect your Arduino to your computer using your USB cable<br />
8. Upload your sketch to your Arduino<br />
9. You should now be POSTing data from your Arduino to your MySQL database. Yippee!<br />


Credits
-------------

<a href="https://github.com/dk4invo">Dhaval Karwa</a><br />
<a href="https://github.com/bsalinas">Ben Salinas</a><br />
<a href="http://arduino.cc/en/Tutorial/WiFiWebClientRepeating">Tom Igoe's WiFiWebClientRepeating sketch</a>