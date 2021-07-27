<h1><span style="font-weight: 400;"><img src="/images/image4.png" alt="" />ArduinoUno/EthernetShield XY-MD02 UDP Sensor</span></h1>
<p><span style="font-weight: 400; color: #ff0000;">July 16, 2021</span></p>
<h2><span style="font-weight: 400;">Overview</span></h2>
<p><span style="font-weight: 400;">Building a sensor based on <span style="color: #333399;"><strong><em>Arduino Uno MCU</em></strong> </span>controller board with it&rsquo;s attached <span style="color: #333399;"><strong><em>Arduino Ethernet shield</em></strong></span> to connect an <span style="color: #333399;"><strong><em>XY-MD02 sensor</em></strong></span> to an <span style="color: #333399;"><strong><em>UDP server</em></strong></span> via a dedicated UDP port.<br />The XY-MD02 sensor is connected to the arduino uno board via a <span style="color: #333399;"><strong><em>RS485 serial interface</em></strong></span>. The RS 485 serial interface is based on a <span style="color: #333399;"><strong><em>MAX-485 chip</em></strong></span>.<br />The Arduino Uno is providing the +5Vdc VCC and GND to both the R485 module and the sensor.<br />It is only for the testing and development of the sensor. <br />In a real case deployment the power supply of the XY-MD02 sensor is going to be a separated power supply. The two system Arduino and XY-MD02 doesn&rsquo;t need to be grounded together and a two wire twisted cable is enough to ensure the serial communication up to 800m. <br />For the ease of testing and development we will use only <span style="color: #333399;"><strong><em>one VCC and one Ground </em></strong></span>to power the all system.<br />The XY-MD02 sensor can use either the standard <span style="color: #333399;"><strong><em>modbus serial</em></strong></span> protocol or a standard <strong><em><span style="color: #333399;">serial UART</span> </em></strong>protocol. Because the sensor is not meant to be used in an array of sensors connected to the same RS485 two wire bus, it is much easier to communicate with the sensor using a <strong><span style="color: #333399;">simple text UART serial protocol</span>.</strong><strong><br /></strong></span></p>
<hr />
<h2><span style="font-weight: 400;">Schematic:</span></h2>
<p><span style="font-weight: 400;"> <img src="/images/image4.png" alt="" /></span></p>
<h2><span style="font-weight: 400;">Hardware requirement:</span></h2>
<p>&nbsp;</p>
<hr />
