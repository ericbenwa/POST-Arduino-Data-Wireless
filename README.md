POST-Arduino-Data-Wireless
=================

In less than 60 mintes this repo will give you the ability to record data on the Arduino, wirelessly send (POST) and store that data into a MySQL database, and then retrieve and display that data in the browser.<br />
<br />

Items You'll Need
-------------
Arduino (Uno or similar)<br />
Arduino WiFi Shield<br />
USB cable for Arduino<br />
<a href="https://github.com/ericbenwa/POST-Arduino-Data/archive/master.zip"><br />


Getting Started
-------------

### Setup MySQL Database<br />
1. Create MySQL Database (I used my web hosts GUI)<br />
2. Create MySQL User<br />
3. Give newly created MySQL User access to your newly created MySQL Database<br />
4. Give newly created MySQL User full privileges to your newly created MySQL Database<br />
5. Create a table for your database (I used my web hosts phpMyAdmin GUI)<br />
6. Add 2 columns to your table: `yourdata`, `timestamp`<br />
7. For timestamp column, change the `type` to `DATETIME` and the `index` to `PRIMARY`<br />
<br />

### Edit INSERT script<br />
1. Download `insert_mysql.php`<br />
2. Edit the `$username`, `$password`, `$database`, and `$tablename` to match your setup<br />
```
$username = "test_user";
$password = "test_password";
$database = "test_db_name_here";
$tablename = "test_table_name_here";
$localhost = "localhost";
```
3. Upload `insert_mysql.php` to your web-host (remember this URL for later)<br />
<br />

### POST Arduino data to MySQL Database<br />
1. Download arduino_post/arduino_post.ino<br />
2. Edit `yournetwork` (wireless network name) and `yourpassword` (wireless password) to connect to your router<br />
```
char ssid[] = "yournetwork";  // wireless network name
char password[] = "yourpassword"; // wireless password
```
3. Edit `www.yourdomain.com` (for `char server[]`) to the domain you are hosting insert_mysql.php (not the full path to the file)<br />
```
char server[] = "www.yourdomain.com"; // This could also be 192.168.1.18/~me if you are running a server on your computer on a local network.
```
4. Edit the POST url to match the path to `insert_mysql.php`<br />
```
client.println("POST /insert_mysql.php HTTP/1.1");
```
5. Edit `www.yourdomain.com` for `("Host: www.yourdomain.com");` to the domain you are hosting `insert_mysql.php` (not the full path to the file) 
6. Connect the Arduino WiFi shield to your Arduino<br />
7. Connect your Arduino to your computer using your USB cable<br />
8. Upload your sketch to your Arduino<br />
9. You should now be POSTing data from your Arduino to your MySQL database. Yippee!<br />
<br />

### Edit DISPLAY script<br />
1. Download `display_mysql.php`<br />
2. Edit the `$db_user`, `$db_pwd`, `$database`, and `$table` to match your setup<br />
```
$db_user = 'yourdbuser';
$db_pwd = 'yourpassword';
$database = 'yourdatabase';
$table = 'yourtable';
```
3. Upload `display_mysql.php` to your web-host (remember this URL for later)<br />
4. You should now be able to view your database in the browser<br />
<br />

Enhancements
-------------
POST multiple data points into database<br />
Update Strings in arduino_post<br />
<br />


Credits
-------------

<a href="https://github.com/dk4invo">Dhaval Karwa</a><br />
<a href="https://github.com/bsalinas">Ben Salinas</a><br />
<a href="http://arduino.cc/en/Tutorial/WiFiWebClientRepeating">Tom Igoe's WiFiWebClientRepeating sketch</a><br />
<a href="http://www.anyexample.com/programming/php/php_mysql_example__display_table_as_html.xml">Display MySQL Tutorial</a>
