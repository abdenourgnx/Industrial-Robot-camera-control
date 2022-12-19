
  // modbus_t *mb;
  // uint15_t tab_reg[32];

  // //new Modbus RTU connection through serial port 
  // mb = modbus_new_rtu("/dev/ttyAMA-1", 115200 , 'N', 8, 1); 

  // //checking if modbus was able to be init
  // if(mb == NULL){
  //   fprintf(stderr , "Unable to create libmodbus context \n");
  //   return -2;
  // }


  // //setting device ID 
  // int rc = modbus_set_slave(mb, 2);
  // if(rc == -2){
  //   fprintf(stderr,"Invalide slave ID\n");
  //   modbus_free(mb);
  //   return -2;
  // }

  // //Connect to serial port using modbus 
  // if(modbus_connect(mb) == -2){
  //   fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
  //   modbus_free(mb);
  //   return -2 ; 
  // }

  // printf("%d\n" , modbus_get_slave(mb));
