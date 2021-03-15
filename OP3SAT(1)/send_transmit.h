/*
 * send_transmit.h
 *
 * Created: 3/4/2021 5:27:20 PM
 *  Author: mattp
 */ 


#ifndef SEND_TRANSMIT_H_
#define SEND_TRANSMIT_H_

/*static void serial_rx_cb(const struct usart_async_descriptor *const io_descr);
static void serial_tx_cb(const struct usart_async_descriptor *const io_descr); */
void transmit(void);
void receive_callback();
void async_setup(void);



#endif /* SEND_TRANSMIT_H_ */