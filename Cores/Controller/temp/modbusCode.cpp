
  // modbus_t *mb;
  // uint16_t tab_reg[32];

  // //new Modbus RTU connection through serial port 
  // mb = modbus_new_rtu("/dev/ttyAMA0", 115200 , 'N', 8, 1); 

  // //checking if modbus was able to be init
  // if(mb == NULL){
  //   fprintf(stderr , "Unable to create libmodbus context \n");
  //   return -1;
  // }


  // //setting device ID 
  // int rc = modbus_set_slave(mb, 3);
  // if(rc == -1){
  //   fprintf(stderr,"Invalide slave ID\n");
  //   modbus_free(mb);
  //   return -1;
  // }

  // //Connect to serial port using modbus 
  // if(modbus_connect(mb) == -1){
  //   fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
  //   modbus_free(mb);
  //   return -1 ; 
  // }

  // printf("%d\n" , modbus_get_slave(mb));








  /////////////////master code /////////
// modbus_t *ctx = modbus_new_rtu("/dev/ttyS0", 9600, 'N', 8, 1);
// if (!ctx) {
//     fprintf(stderr, "Failed to create the context: %s\n", modbus_strerror(errno));
//     exit(1);
// }

// if (modbus_connect(ctx) == -1) {
//     fprintf(stderr, "Unable to connect: %s\n", modbus_strerror(errno));
//     modbus_free(ctx);
//     exit(1);
// }

// //Set the Modbus address of the remote slave (to 3)
// modbus_set_slave(ctx, 3);


// uint16_t reg[5];// will store read registers values

// //Read 5 holding registers starting from address 10
// int num = modbus_read_registers(ctx, 10, 5, reg);
// if (num != 5) {// number of read registers is not the one expected
//     fprintf(stderr, "Failed to read: %s\n", modbus_strerror(errno));
// }

// modbus_close(ctx);
// modbus_free(ctx);





////////////////////// slave code /////////////////////
//Prepare a Modbus mapping with 30 holding registers
//(plus no output coil, one input coil and two input registers)
//This will also automatically set the value of each register to 0
// modbus_mapping_t *mapping = modbus_mapping_new(0, 1, 30, 2);
// if (!mapping) {
//     fprintf(stderr, "Failed to allocate the mapping: %s\n", modbus_strerror(errno));
//     exit(1);
// }


// //Example: set register 12 to integer value 623
// mapping->tab_registers[12] = 623;


// modbus_t *ctx = modbus_new_rtu("/dev/ttyS0", 9600, 'N', 8, 1);
// if (!ctx) {
//     fprintf(stderr, "Failed to create the context: %s\n", modbus_strerror(errno));
//     exit(1);
// }

// //Set the Modbus address of this slave (to 3)
// modbus_set_slave(ctx, 3);


// if (modbus_connect(ctx) == -1) {
//     fprintf(stderr, "Unable to connect: %s\n", modbus_strerror(errno));
//     modbus_free(ctx);
//     exit(1);
// }


// uint8_t req[MODBUS_RTU_MAX_ADU_LENGTH];// request buffer
// int len;// length of the request/response

// while(1) {
//     len = modbus_receive(ctx, req);
//     if (len == -1) break;

//     len = modbus_reply(ctx, req, len, mapping);
//     if (len == -1) break;
// }
// printf("Exit the loop: %s\n", modbus_strerror(errno));

// modbus_mapping_free(mapping);
// modbus_close(ctx);
// modbus_free(ctx);