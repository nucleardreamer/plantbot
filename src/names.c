#include <usb_names.h>

#define MANUFACTURER_NAME	{'S', 'P', 'A', 'C', 'E', 'B', 'U', 'C', 'K', 'E', 'T', 'S'}
#define MANUFACTURER_NAME_LEN	12
#define PRODUCT_NAME		{'P', 'L', 'A', 'N', 'T', 'B', 'O', 'T'}
#define PRODUCT_NAME_LEN	8

struct usb_string_descriptor_struct usb_string_manufacturer_name = {
  2 + MANUFACTURER_NAME_LEN * 2,
  3,
  MANUFACTURER_NAME
};
struct usb_string_descriptor_struct usb_string_product_name = {
  2 + PRODUCT_NAME_LEN * 2,
  3,
  PRODUCT_NAME
};
