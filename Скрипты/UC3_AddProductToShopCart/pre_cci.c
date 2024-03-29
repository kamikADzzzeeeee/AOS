# 1 "c:\\users\\user\\documents\\vugen\\scripts\\uc3_addproducttoshopcart\\\\combined_UC3_AddProductToShopCart.c"
# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h" 1
 
 












 











# 103 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"





















































		


		typedef unsigned size_t;
	
	
        
	

















	

 



















 
 
 
 
 


 
 
 
 
 
 














int     lr_start_transaction   (char * transaction_name);
int lr_start_sub_transaction          (char * transaction_name, char * trans_parent);
long lr_start_transaction_instance    (char * transaction_name, long parent_handle);
int   lr_start_cross_vuser_transaction		(char * transaction_name, char * trans_id_param); 



int     lr_end_transaction     (char * transaction_name, int status);
int lr_end_sub_transaction            (char * transaction_name, int status);
int lr_end_transaction_instance       (long transaction, int status);
int   lr_end_cross_vuser_transaction	(char * transaction_name, char * trans_id_param, int status);


 
typedef char* lr_uuid_t;
 



lr_uuid_t lr_generate_uuid();

 


int lr_generate_uuid_free(lr_uuid_t uuid);

 



int lr_generate_uuid_on_buf(lr_uuid_t buf);

   
# 273 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
int lr_start_distributed_transaction  (char * transaction_name, lr_uuid_t correlator, long timeout  );

   







int lr_end_distributed_transaction  (lr_uuid_t correlator, int status);


double lr_stop_transaction            (char * transaction_name);
double lr_stop_transaction_instance   (long parent_handle);


void lr_resume_transaction           (char * trans_name);
void lr_resume_transaction_instance  (long trans_handle);


int lr_update_transaction            (const char *trans_name);


 
void lr_wasted_time(long time);


 
int lr_set_transaction(const char *name, double duration, int status);
 
long lr_set_transaction_instance(const char *name, double duration, int status, long parent_handle);


int   lr_user_data_point                      (char *, double);
long lr_user_data_point_instance                   (char *, double, long);
 



int lr_user_data_point_ex(const char *dp_name, double value, int log_flag);
long lr_user_data_point_instance_ex(const char *dp_name, double value, long parent_handle, int log_flag);


int lr_transaction_add_info      (const char *trans_name, char *info);
int lr_transaction_instance_add_info   (long trans_handle, char *info);
int lr_dpoint_add_info           (const char *dpoint_name, char *info);
int lr_dpoint_instance_add_info        (long dpoint_handle, char *info);


double lr_get_transaction_duration       (char * trans_name);
double lr_get_trans_instance_duration    (long trans_handle);
double lr_get_transaction_think_time     (char * trans_name);
double lr_get_trans_instance_think_time  (long trans_handle);
double lr_get_transaction_wasted_time    (char * trans_name);
double lr_get_trans_instance_wasted_time (long trans_handle);
int    lr_get_transaction_status		 (char * trans_name);
int	   lr_get_trans_instance_status		 (long trans_handle);

 



int lr_set_transaction_status(int status);

 



int lr_set_transaction_status_by_name(int status, const char *trans_name);
int lr_set_transaction_instance_status(int status, long trans_handle);


typedef void* merc_timer_handle_t;
 

merc_timer_handle_t lr_start_timer();
double lr_end_timer(merc_timer_handle_t timer_handle);


 
 
 
 
 
 











 



int   lr_rendezvous  (char * rendezvous_name);
 




int   lr_rendezvous_ex (char * rendezvous_name);



 
 
 
 
 
char *lr_get_vuser_ip (void);
void   lr_whoami (int *vuser_id, char ** sgroup, int *scid);
char *	  lr_get_host_name (void);
char *	  lr_get_master_host_name (void);

 
long     lr_get_attrib_long	(char * attr_name);
char *   lr_get_attrib_string	(char * attr_name);
double   lr_get_attrib_double      (char * attr_name);

char * lr_paramarr_idx(const char * paramArrayName, unsigned int index);
char * lr_paramarr_random(const char * paramArrayName);
int    lr_paramarr_len(const char * paramArrayName);

int	lr_param_unique(const char * paramName);
int lr_param_sprintf(const char * paramName, const char * format, ...);


 
 
static void *ci_this_context = 0;






 








void lr_continue_on_error (int lr_continue);
char *   lr_unmask (const char *EncodedString);
char *   lr_decrypt (const char *EncodedString);


 
 
 
 
 
 



 







 















void   lr_abort (void);
void lr_exit(int exit_option, int exit_status);
void lr_abort_ex (unsigned long flags);

void   lr_peek_events (void);


 
 
 
 
 


void   lr_think_time (double secs);

 


void lr_force_think_time (double secs);


 
 
 
 
 



















int   lr_msg (char * fmt, ...);
int   lr_debug_message (unsigned int msg_class,
									    char * format,
										...);
# 513 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
void   lr_new_prefix (int type,
                                 char * filename,
                                 int line);
# 516 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
int   lr_log_message (char * fmt, ...);
int   lr_message (char * fmt, ...);
int   lr_error_message (char * fmt, ...);
int   lr_output_message (char * fmt, ...);
int   lr_vuser_status_message (char * fmt, ...);
int   lr_error_message_without_fileline (char * fmt, ...);
int   lr_fail_trans_with_error (char * fmt, ...);

 
 
 
 
 
# 540 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"

 
 
 
 
 





int   lr_next_row ( char * table);
int lr_advance_param ( char * param);



														  
														  

														  
														  

													      
 


char *   lr_eval_string (char * str);
int   lr_eval_string_ext (const char *in_str,
                                     unsigned long const in_len,
                                     char ** const out_str,
                                     unsigned long * const out_len,
                                     unsigned long const options,
                                     const char *file,
								     long const line);
# 574 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
void   lr_eval_string_ext_free (char * * pstr);

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int lr_param_increment (char * dst_name,
                              char * src_name);
# 597 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"













											  
											  

											  
											  
											  

int	  lr_save_var (char *              param_val,
							  unsigned long const param_val_len,
							  unsigned long const options,
							  char *			  param_name);
# 621 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
int   lr_save_string (const char * param_val, const char * param_name);



int   lr_set_custom_error_message (const char * param_val, ...);

int   lr_remove_custom_error_message ();


int   lr_free_parameter (const char * param_name);
int   lr_save_int (const int param_val, const char * param_name);
int   lr_save_timestamp (const char * tmstampParam, ...);
int   lr_save_param_regexp (const char *bufferToScan, unsigned int bufSize, ...);

int   lr_convert_double_to_integer (const char *source_param_name, const char * target_param_name);
int   lr_convert_double_to_double (const char *source_param_name, const char *format_string, const char * target_param_name);

 
 
 
 
 
 
# 700 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
void   lr_save_datetime (const char *format, int offset, const char *name);









 











 
 
 
 
 






 



char * lr_error_context_get_entry (char * key);

 



long   lr_error_context_get_error_id (void);


 
 
 

int lr_table_get_rows_num (char * param_name);

int lr_table_get_cols_num (char * param_name);

char * lr_table_get_cell_by_col_index (char * param_name, int row, int col);

char * lr_table_get_cell_by_col_name (char * param_name, int row, const char* col_name);

int lr_table_get_column_name_by_index (char * param_name, int col, 
											char * * const col_name,
											size_t * col_name_len);
# 761 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"

int lr_table_get_column_name_by_index_free (char * col_name);

 
 
 
 
# 776 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
int   lr_zip (const char* param1, const char* param2);
int   lr_unzip (const char* param1, const char* param2);

 
 
 
 
 
 
 
 

 
 
 
 
 
 
int   lr_param_substit (char * file,
                                   int const line,
                                   char * in_str,
                                   size_t const in_len,
                                   char * * const out_str,
                                   size_t * const out_len);
# 800 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
void   lr_param_substit_free (char * * pstr);


 
# 812 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"





char *   lrfnc_eval_string (char * str,
                                      char * file_name,
                                      long const line_num);
# 820 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"


int   lrfnc_save_string ( const char * param_val,
                                     const char * param_name,
                                     const char * file_name,
                                     long const line_num);
# 826 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"

int   lrfnc_free_parameter (const char * param_name );







typedef struct _lr_timestamp_param
{
	int iDigits;
}lr_timestamp_param;

extern const lr_timestamp_param default_timestamp_param;

int   lrfnc_save_timestamp (const char * param_name, const lr_timestamp_param* time_param);

int lr_save_searched_string(char * buffer, long buf_size, unsigned int occurrence,
			    char * search_string, int offset, unsigned int param_val_len, 
			    char * param_name);

 
char *   lr_string (char * str);

 
# 929 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"

int   lr_save_value (char * param_val,
                                unsigned long const param_val_len,
                                unsigned long const options,
                                char * param_name,
                                char * file_name,
                                long const line_num);
# 936 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"


 
 
 
 
 











int   lr_printf (char * fmt, ...);
 
int   lr_set_debug_message (unsigned int msg_class,
                                       unsigned int swtch);
# 958 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
unsigned int   lr_get_debug_message (void);


 
 
 
 
 

void   lr_double_think_time ( double secs);
void   lr_usleep (long);


 
 
 
 
 
 




int *   lr_localtime (long offset);


int   lr_send_port (long port);


# 1034 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"



struct _lr_declare_identifier{
	char signature[24];
	char value[128];
};

int   lr_pt_abort (void);

void vuser_declaration (void);






# 1063 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"


# 1075 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
















 
 
 
 
 







int    _lr_declare_transaction   (char * transaction_name);


 
 
 
 
 







int   _lr_declare_rendezvous  (char * rendezvous_name);

 
 
 
 
 


typedef int PVCI;






typedef int VTCERR;









PVCI   vtc_connect(char * servername, int portnum, int options);
VTCERR   vtc_disconnect(PVCI pvci);
VTCERR   vtc_get_last_error(PVCI pvci);
VTCERR   vtc_query_column(PVCI pvci, char * columnName, int columnIndex, char * *outvalue);
VTCERR   vtc_query_row(PVCI pvci, int rowIndex, char * **outcolumns, char * **outvalues);
VTCERR   vtc_send_message(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_if_unique(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_row1(PVCI pvci, char * columnNames, char * messages, char * delimiter, unsigned char sendflag, unsigned short *outUpdates);
VTCERR   vtc_update_message(PVCI pvci, char * column, int index , char * message, unsigned short *outRc);
VTCERR   vtc_update_message_ifequals(PVCI pvci, char * columnName, int index,	char * message, char * ifmessage, unsigned short 	*outRc);
VTCERR   vtc_update_row1(PVCI pvci, char * columnNames, int index , char * messages, char * delimiter, unsigned short *outUpdates);
VTCERR   vtc_retrieve_message(PVCI pvci, char * column, char * *outvalue);
VTCERR   vtc_retrieve_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues);
VTCERR   vtc_retrieve_row(PVCI pvci, char * **outcolumns, char * **outvalues);
VTCERR   vtc_rotate_message(PVCI pvci, char * column, char * *outvalue, unsigned char sendflag);
VTCERR   vtc_rotate_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_rotate_row(PVCI pvci, char * **outcolumns, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_increment(PVCI pvci, char * column, int index , int incrValue, int *outValue);
VTCERR   vtc_clear_message(PVCI pvci, char * column, int index , unsigned short *outRc);
VTCERR   vtc_clear_column(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_ensure_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_drop_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_clear_row(PVCI pvci, int rowIndex, unsigned short *outRc);
VTCERR   vtc_create_column(PVCI pvci, char * column,unsigned short *outRc);
VTCERR   vtc_column_size(PVCI pvci, char * column, int *size);
void   vtc_free(char * msg);
void   vtc_free_list(char * *msglist);

VTCERR   lrvtc_connect(char * servername, int portnum, int options);
VTCERR   lrvtc_disconnect();
VTCERR   lrvtc_query_column(char * columnName, int columnIndex);
VTCERR   lrvtc_query_row(int columnIndex);
VTCERR   lrvtc_send_message(char * columnName, char * message);
VTCERR   lrvtc_send_if_unique(char * columnName, char * message);
VTCERR   lrvtc_send_row1(char * columnNames, char * messages, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_update_message(char * columnName, int index , char * message);
VTCERR   lrvtc_update_message_ifequals(char * columnName, int index, char * message, char * ifmessage);
VTCERR   lrvtc_update_row1(char * columnNames, int index , char * messages, char * delimiter);
VTCERR   lrvtc_retrieve_message(char * columnName);
VTCERR   lrvtc_retrieve_messages1(char * columnNames, char * delimiter);
VTCERR   lrvtc_retrieve_row();
VTCERR   lrvtc_rotate_message(char * columnName, unsigned char sendflag);
VTCERR   lrvtc_rotate_messages1(char * columnNames, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_rotate_row(unsigned char sendflag);
VTCERR   lrvtc_increment(char * columnName, int index , int incrValue);
VTCERR   lrvtc_noop();
VTCERR   lrvtc_clear_message(char * columnName, int index);
VTCERR   lrvtc_clear_column(char * columnName); 
VTCERR   lrvtc_ensure_index(char * columnName); 
VTCERR   lrvtc_drop_index(char * columnName); 
VTCERR   lrvtc_clear_row(int rowIndex);
VTCERR   lrvtc_create_column(char * columnName);
VTCERR   lrvtc_column_size(char * columnName);



 
 
 
 
 

 
int lr_enable_ip_spoofing();
int lr_disable_ip_spoofing();


 




int lr_convert_string_encoding(char * sourceString, char * fromEncoding, char * toEncoding, char * paramName);
int lr_read_file(const char *filename, const char *outputParam, int continueOnError);

int lr_get_char_count(const char * string);


 
int lr_db_connect (char * pFirstArg, ...);
int lr_db_disconnect (char * pFirstArg,	...);
int lr_db_executeSQLStatement (char * pFirstArg, ...);
int lr_db_dataset_action(char * pFirstArg, ...);
int lr_checkpoint(char * pFirstArg,	...);
int lr_db_getvalue(char * pFirstArg, ...);







 
 



















# 1 "c:\\users\\user\\documents\\vugen\\scripts\\uc3_addproducttoshopcart\\\\combined_UC3_AddProductToShopCart.c" 2

# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/SharedParameter.h" 1



 
 
 
 
# 100 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/SharedParameter.h"






typedef int PVCI2;






typedef int VTCERR2;


 
 
 

 
extern PVCI2    vtc_connect(char *servername, int portnum, int options);
extern VTCERR2  vtc_disconnect(PVCI2 pvci);
extern VTCERR2  vtc_get_last_error(PVCI2 pvci);

 
extern VTCERR2  vtc_query_column(PVCI2 pvci, char *columnName, int columnIndex, char **outvalue);
extern VTCERR2  vtc_query_row(PVCI2 pvci, int columnIndex, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_send_message(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_if_unique(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_row1(PVCI2 pvci, char *columnNames, char *messages, char *delimiter,  unsigned char sendflag, unsigned short *outUpdates);
extern VTCERR2  vtc_update_message(PVCI2 pvci, char *column, int index , char *message, unsigned short *outRc);
extern VTCERR2  vtc_update_message_ifequals(PVCI2 pvci, char	*columnName, int index,	char *message, char	*ifmessage,	unsigned short 	*outRc);
extern VTCERR2  vtc_update_row1(PVCI2 pvci, char *columnNames, int index , char *messages, char *delimiter, unsigned short *outUpdates);
extern VTCERR2  vtc_retrieve_message(PVCI2 pvci, char *column, char **outvalue);
extern VTCERR2  vtc_retrieve_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues);
extern VTCERR2  vtc_retrieve_row(PVCI2 pvci, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_rotate_message(PVCI2 pvci, char *column, char **outvalue, unsigned char sendflag);
extern VTCERR2  vtc_rotate_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues, unsigned char sendflag);
extern VTCERR2  vtc_rotate_row(PVCI2 pvci, char ***outcolumns, char ***outvalues, unsigned char sendflag);
extern VTCERR2	vtc_increment(PVCI2 pvci, char *column, int index , int incrValue, int *outValue);
extern VTCERR2  vtc_clear_message(PVCI2 pvci, char *column, int index , unsigned short *outRc);
extern VTCERR2  vtc_clear_column(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_clear_row(PVCI2 pvci, int rowIndex, unsigned short *outRc);

extern VTCERR2  vtc_create_column(PVCI2 pvci, char *column,unsigned short *outRc);
extern VTCERR2  vtc_column_size(PVCI2 pvci, char *column, int *size);
extern VTCERR2  vtc_ensure_index(PVCI2 pvci, char *column, unsigned short *outRc);
extern VTCERR2  vtc_drop_index(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_noop(PVCI2 pvci);

 
extern void vtc_free(char *msg);
extern void vtc_free_list(char **msglist);

 


 




 




















 




 
 
 

extern VTCERR2  lrvtc_connect(char *servername, int portnum, int options);
extern VTCERR2  lrvtc_disconnect();
extern VTCERR2  lrvtc_query_column(char *columnName, int columnIndex);
extern VTCERR2  lrvtc_query_row(int columnIndex);
extern VTCERR2  lrvtc_send_message(char *columnName, char *message);
extern VTCERR2  lrvtc_send_if_unique(char *columnName, char *message);
extern VTCERR2  lrvtc_send_row1(char *columnNames, char *messages, char *delimiter,  unsigned char sendflag);
extern VTCERR2  lrvtc_update_message(char *columnName, int index , char *message);
extern VTCERR2  lrvtc_update_message_ifequals(char *columnName, int index, char 	*message, char *ifmessage);
extern VTCERR2  lrvtc_update_row1(char *columnNames, int index , char *messages, char *delimiter);
extern VTCERR2  lrvtc_retrieve_message(char *columnName);
extern VTCERR2  lrvtc_retrieve_messages1(char *columnNames, char *delimiter);
extern VTCERR2  lrvtc_retrieve_row();
extern VTCERR2  lrvtc_rotate_message(char *columnName, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_messages1(char *columnNames, char *delimiter, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_row(unsigned char sendflag);
extern VTCERR2  lrvtc_increment(char *columnName, int index , int incrValue);
extern VTCERR2  lrvtc_clear_message(char *columnName, int index);
extern VTCERR2  lrvtc_clear_column(char *columnName);
extern VTCERR2  lrvtc_clear_row(int rowIndex);
extern VTCERR2  lrvtc_create_column(char *columnName);
extern VTCERR2  lrvtc_column_size(char *columnName);
extern VTCERR2  lrvtc_ensure_index(char *columnName);
extern VTCERR2  lrvtc_drop_index(char *columnName);

extern VTCERR2  lrvtc_noop();

 
 
 

                               


 
 
 





















# 2 "c:\\users\\user\\documents\\vugen\\scripts\\uc3_addproducttoshopcart\\\\combined_UC3_AddProductToShopCart.c" 2

# 1 "globals.h" 1



 
 

# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/web_api.h" 1







# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h" 1



























































 




 



 











 





















 
 
 

  int
	web_add_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_add_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
	
  int
	web_add_auto_header(
		const char *		mpszHeader,
		const char *		mpszValue);

  int
	web_add_header(
		const char *		mpszHeader,
		const char *		mpszValue);
  int
	web_add_cookie(
		const char *		mpszCookie);
  int
	web_cleanup_auto_headers(void);
  int
	web_cleanup_cookies(void);
  int
	web_concurrent_end(
		const char * const	mpszReserved,
										 
		...								 
	);
  int
	web_concurrent_start(
		const char * const	mpszConcurrentGroupName,
										 
										 
		...								 
										 
	);
  int
	web_create_html_param(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim);
  int
	web_create_html_param_ex(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim,
		const char *		mpszNum);
  int
	web_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_disable_keep_alive(void);
  int
	web_enable_keep_alive(void);
  int
	web_find(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_get_int_property(
		const int			miHttpInfoType);
  int
	web_image(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_image_check(
		const char *		mpszName,
		...);
  int
	web_java_check(
		const char *		mpszName,
		...);
  int
	web_link(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

	
  int
	web_global_verification(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
  int
	web_reg_find(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
				
  int
	web_reg_save_param(
		const char *		mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 

  int
	web_convert_param(
		const char * 		mpszParamName, 
										 
		...);							 
										 
										 


										 

										 
  int
	web_remove_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
				
  int
	web_remove_auto_header(
		const char *		mpszHeaderName,
		...);							 
										 



  int
	web_remove_cookie(
		const char *		mpszCookie);

  int
	web_save_header(
		const char *		mpszType,	 
		const char *		mpszName);	 
  int
	web_set_certificate(
		const char *		mpszIndex);
  int
	web_set_certificate_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_set_connections_limit(
		const char *		mpszLimit);
  int
	web_set_max_html_param_len(
		const char *		mpszLen);
  int
	web_set_max_retries(
		const char *		mpszMaxRetries);
  int
	web_set_proxy(
		const char *		mpszProxyHost);
  int
	web_set_pac(
		const char *		mpszPacUrl);
  int
	web_set_proxy_bypass(
		const char *		mpszBypass);
  int
	web_set_secure_proxy(
		const char *		mpszProxyHost);
  int
	web_set_sockets_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue
	);
  int
	web_set_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue,
		...								 
	);
  int
	web_set_timeout(
		const char *		mpszWhat,
		const char *		mpszTimeout);
  int
	web_set_user(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);

  int
	web_sjis_to_euc_param(
		const char *		mpszParamName,
										 
		const char *		mpszParamValSjis);
										 

  int
	web_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_submit_form(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	spdy_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_set_proxy_bypass_local(
		const char * mpszNoLocal
		);

  int 
	web_cache_cleanup(void);

  int
	web_create_html_query(
		const char* mpszStartQuery,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_create_radio_button_param(
		const char *NameFiled,
		const char *NameAndVal,
		const char *ParamName
		);

  int
	web_convert_from_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										
  int
	web_convert_to_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_ex(
		const char * mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_xpath(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_json(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_regexp(
		 const char * mpszParamName,
		 ...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_attrib(
		const char * mpszParamName,
		...);
										 
										 
										 
										 
										 
										 
										 		
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_run(
		const char * mpszCode,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_reset(void);

  int
	web_convert_date_param(
		const char * 		mpszParamName,
		...);










# 789 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h"


# 802 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h"



























# 840 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h"

 
 
 


  int
	FormSubmit(
		const char *		mpszFormName,
		...);
  int
	InitWebVuser(void);
  int
	SetUser(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);
  int
	TerminateWebVuser(void);
  int
	URL(
		const char *		mpszUrlName);
























# 908 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h"


  int
	web_rest(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 

  int
web_stream_open(
	const char *		mpszArg1,
	...
);
  int
	web_stream_wait(
		const char *		mpszArg1,
		...
	);

  int
	web_stream_close(
		const char *		mpszArg1,
		...
	);

  int
web_stream_play(
	const char *		mpszArg1,
	...
	);

  int
web_stream_pause(
	const char *		mpszArg1,
	...
	);

  int
web_stream_seek(
	const char *		mpszArg1,
	...
	);

  int
web_stream_get_param_int(
	const char*			mpszStreamID,
	const int			miStateType
	);

  double
web_stream_get_param_double(
	const char*			mpszStreamID,
	const int			miStateType
	);

  int
web_stream_get_param_string(
	const char*			mpszStreamID,
	const int			miStateType,
	const char*			mpszParameterName
	);

  int
web_stream_set_param_int(
	const char*			mpszStreamID,
	const int			miStateType,
	const int			miStateValue
	);

  int
web_stream_set_param_double(
	const char*			mpszStreamID,
	const int			miStateType,
	const double		mdfStateValue
	);

  int
web_stream_set_custom_mpd(
	const char*			mpszStreamID,
	const char*			aMpdBuf
	);

 
 
 






# 9 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/web_api.h" 2

















 







 















  int
	web_reg_add_cookie(
		const char *		mpszCookie,
		...);							 
										 

  int
	web_report_data_point(
		const char *		mpszEventType,
		const char *		mpszEventName,
		const char *		mpszDataPointName,
		const char *		mpszLAST);	 
										 
										 
										 

  int
	web_text_link(
		const char *		mpszStepName,
		...);

  int
	web_element(
		const char *		mpszStepName,
		...);

  int
	web_image_link(
		const char *		mpszStepName,
		...);

  int
	web_static_image(
		const char *		mpszStepName,
		...);

  int
	web_image_submit(
		const char *		mpszStepName,
		...);

  int
	web_button(
		const char *		mpszStepName,
		...);

  int
	web_edit_field(
		const char *		mpszStepName,
		...);

  int
	web_radio_group(
		const char *		mpszStepName,
		...);

  int
	web_check_box(
		const char *		mpszStepName,
		...);

  int
	web_list(
		const char *		mpszStepName,
		...);

  int
	web_text_area(
		const char *		mpszStepName,
		...);

  int
	web_map_area(
		const char *		mpszStepName,
		...);

  int
	web_eval_java_script(
		const char *		mpszStepName,
		...);

  int
	web_reg_dialog(
		const char *		mpszArg1,
		...);

  int
	web_reg_cross_step_download(
		const char *		mpszArg1,
		...);

  int
	web_browser(
		const char *		mpszStepName,
		...);

  int
	web_control(
		const char *		mpszStepName,
		...);

  int
	web_set_rts_key(
		const char *		mpszArg1,
		...);

  int
	web_save_param_length(
		const char * 		mpszParamName,
		...);

  int
	web_save_timestamp_param(
		const char * 		mpszParamName,
		...);

  int
	web_load_cache(
		const char *		mpszStepName,
		...);							 
										 

  int
	web_dump_cache(
		const char *		mpszStepName,
		...);							 
										 
										 

  int
	web_reg_find_in_log(
		const char *		mpszArg1,
		...);							 
										 
										 

  int
	web_get_sockets_info(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 

  int
	web_add_cookie_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

  int
	web_hook_java_script(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

 
 
 
 
 
 
 
 
 
 
 
 
  int
	web_reg_async_attributes(
		const char *		mpszArg,
		...
	);

 
 
 
 
 
 
  int
	web_sync(
		 const char *		mpszArg1,
		 ...
	);

 
 
 
 
  int
	web_stop_async(
		const char *		mpszArg1,
		...
	);

 
 
 
 
 

 
 
 

typedef enum WEB_ASYNC_CB_RC_ENUM_T
{
	WEB_ASYNC_CB_RC_OK,				 

	WEB_ASYNC_CB_RC_ABORT_ASYNC_NOT_ERROR,
	WEB_ASYNC_CB_RC_ABORT_ASYNC_ERROR,
										 
										 
										 
										 
	WEB_ASYNC_CB_RC_ENUM_COUNT
} WEB_ASYNC_CB_RC_ENUM;

 
 
 

typedef enum WEB_CONVERS_CB_CALL_REASON_ENUM_T
{
	WEB_CONVERS_CB_CALL_REASON_BUFFER_RECEIVED,
	WEB_CONVERS_CB_CALL_REASON_END_OF_TASK,

	WEB_CONVERS_CB_CALL_REASON_ENUM_COUNT
} WEB_CONVERS_CB_CALL_REASON_ENUM;

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

typedef
int														 
	(*RequestCB_t)();

typedef
int														 
	(*ResponseBodyBufferCB_t)(
		  const char *		aLastBufferStr,
		  int				aLastBufferLen,
		  const char *		aAccumulatedStr,
		  int				aAccumulatedLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseCB_t)(
		  const char *		aResponseHeadersStr,
		  int				aResponseHeadersLen,
		  const char *		aResponseBodyStr,
		  int				aResponseBodyLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseHeadersCB_t)(
		  int				aHttpStatusCode,
		  const char *		aAccumulatedHeadersStr,
		  int				aAccumulatedHeadersLen);



 
 
 

typedef enum WEB_CONVERS_UTIL_RC_ENUM_T
{
	WEB_CONVERS_UTIL_RC_OK,
	WEB_CONVERS_UTIL_RC_CONVERS_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_TASK_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_UNAVIALABLE,
	WEB_CONVERS_UTIL_RC_INVALID_ARGUMENT,

	WEB_CONVERS_UTIL_RC_ENUM_COUNT
} WEB_CONVERS_UTIL_RC_ENUM;

 
 
 

  int					 
	web_util_set_request_url(
		  const char *		aUrlStr);

  int					 
	web_util_set_request_body(
		  const char *		aRequestBodyStr);

  int					 
	web_util_set_formatted_request_body(
		  const char *		aRequestBodyStr);


 
 
 
 
 

 
 
 
 
 

 
 
 
 
 
 
 
 

 
 
  int
web_websocket_connect(
		 const char *	mpszArg1,
		 ...
		 );


 
 
 
 
 																						
  int
web_websocket_send(
	   const char *		mpszArg1,
		...
	   );

 
 
 
 
 
 
  int
web_websocket_close(
		const char *	mpszArg1,
		...
		);

 
typedef
void														
(*OnOpen_t)(
			  const char* connectionID,  
			  const char * responseHeader,  
			  int length  
);

typedef
void														
(*OnMessage_t)(
	  const char* connectionID,  
	  int isbinary,  
	  const char * data,  
	  int length  
	);

typedef
void														
(*OnError_t)(
	  const char* connectionID,  
	  const char * message,  
	  int length  
	);

typedef
void														
(*OnClose_t)(
	  const char* connectionID,  
	  int isClosedByClient,  
	  int code,  
	  const char* reason,  
	  int length  
	 );
 
 
 
 
 





# 7 "globals.h" 2

# 1 "lrw_custom_body.h" 1
 




# 8 "globals.h" 2

# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/stdio.h" 1



# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/stddef.h" 1













typedef unsigned int uintptr_t;








typedef int intptr_t;








typedef int ptrdiff_t;





typedef unsigned short wchar_t;




typedef long time_t;




typedef long clock_t;




typedef wchar_t wint_t;
typedef wchar_t wctype_t;




typedef char *	va_list;



 





# 4 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/stdio.h" 2



 








 











 























# 79 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/stdio.h"








typedef struct _iobuf
{
	void* _Placeholder;
} FILE;




typedef long long fpos_t;




FILE* __acrt_iob_func(unsigned);







 



# 126 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/stdio.h"


int _fgetchar(void);
int _fputchar(int);
int _flushall(void);
int _rmtmp(void);
FILE * _fsopen(const char *, const char *, int);



void clearerr(FILE *);
int fclose(FILE *);
int _fcloseall(void);

FILE * _fdopen(int, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
int fgetc(FILE *);
int fgetpos(FILE *, fpos_t *);
char * fgets(char *, int, FILE *);

int _fileno(FILE *);

FILE * fopen(const char *, const char *);
int fprintf(FILE *, const char *, ...);
int fputc(int, FILE *);

int fputs(const char *, FILE *);
size_t fread(void *, size_t, size_t, FILE *);
FILE * freopen(const char *, const char *, FILE *);
int fscanf(FILE *, const char *, ...);
int fsetpos(FILE *, const fpos_t *);
int fseek(FILE *, long, int);
long ftell(FILE *);
size_t fwrite(const void *, size_t, size_t, FILE *);
int getc(FILE *);
int getchar(void);
char * gets(char *);
int _getw(FILE *);
int _pclose(FILE *);
FILE * _popen(const char *, const char *);
int printf(const char *, ...);
int putc(int, FILE *);
int putchar(int);
int puts(const char *);
int _putw(int, FILE *);
int remove(const char *);
int rename(const char *, const char *);
void rewind(FILE *);
int scanf(const char *, ...);
void setbuf(FILE *, char *);
int setvbuf(FILE *, char *, int, size_t);
int _snprintf(char *, size_t, const char *, ...);
int sprintf(char *, const char *, ...);
int sscanf(const char *, const char *, ...);
char * _tempnam(char *, char *);
FILE * tmpfile(void);
char * tmpnam(char *);
int ungetc(int, FILE *);
int _unlink(const char *);
int vfprintf(FILE *, const char *, va_list);
int vprintf(const char *, va_list);
int _vsnprintf(char *, size_t, const char *, va_list);
int vsprintf(char *, const char *, va_list);








# 9 "globals.h" 2

# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/string.h" 1
 








# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/stddef.h" 1






























































 





# 10 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/string.h" 2










void *	 memchr(const void *, int, size_t);
int 	 memcmp(const void *, const void *, size_t);
void * 	 memcpy(void *, const void *, size_t);
void *	 memmove(void *, const void *, size_t);
void *	 memset(void *, int, size_t);

char 	*strcat(char *, const char *);
char 	*strchr(const char *, int);
int	 strcmp(const char *, const char *);
int	 strcoll(const char *, const char *);
char 	*strcpy(char *, const char *);
size_t	 strcspn(const char *, const char *);
char 	*strerror(int);
size_t	 strlen(const char *);
char 	*strncat(char *, const char *, size_t);
int	 strncmp(const char *, const char *, size_t);
char 	*strncpy(char *, const char *, size_t);
char 	*strpbrk(const char *, const char *);
char 	*strrchr(const char *, int);
size_t	 strspn(const char *, const char *);
char 	*strstr(const char *, const char *);
char 	*strtok(char *, const char *);

void *	 memccpy(void *, const void *, int, size_t);
int	 strcmpi(const char *, const char *);
char 	*strdup(const char *);
int	 strnicmp(const char *, const char *, size_t);
void	 swab(const char *, char *, size_t);

# 10 "globals.h" 2

# 1 "..\\library\\user_lib.h" 1


# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/math.h" 1
 












extern double __infinity();






 

extern double atan(double);
extern double cos(double);
extern double sin(double);
extern double tan(double);
extern double tanh(double);
extern double frexp(double, int *);
extern double modf(double, double *);
extern double ceil(double);
extern double fabs(double);
extern double floor(double);

extern double acos (double);
extern double asin (double);
extern double atan2 (double, double);
extern double cosh (double);
extern double sinh (double);
extern double exp(double);
extern double ldexp(double, int);
extern double log(double);
extern double log10(double);
extern double pow(double, double);
extern double sqrt(double);
extern double fmod(double, double);


 

extern int isnan (double);
extern int finite (double);
extern double copysign(double, double);
extern int ilogb (double);

extern double asinh (double);
extern double cbrt(double);
extern double nextafter (double, double);
extern double rint (double);
extern double scalbn (double, int);

extern double log1p(double);
extern double expm1(double);

extern double acosh (double);
extern double atanh(double);
extern double remainder (double, double);
extern double lgamma (double);
extern double erf (double);
extern double erfc (double);
extern double y0 (double);
extern double y1 (double);
extern double yn(int, double);
extern double j0(double);
extern double j1 (double);
extern double jn (int, double);


extern double hypot (double, double);


 

struct exception
{
  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
};




extern int _matherr (struct exception *e);


 








 

























# 3 "..\\library\\user_lib.h" 2


void readRowFromParameters(char userdata[800]){
	 
    char login[20];
    char email[40];
    char password[20];
    char firstName[20];
	char lastName[20]; 
	char phoneNumber[15];
	char city[20];
	char adress[50];
	char stateProvinceRegion[15];
	char postalCode[15];
	char userId[20];
	char plBase64[30];
	char authToken[300];
	char shortCountry[10];
	char countryId[5];
    char row[800] = "";
     
    
    strcpy(row, userdata);
    
     
    sscanf(row,"%s	%s	%s	%s	%s	%s	%s	%s	%s	%s	%s	%s	%s	%s	%s"
          	,login
          	,&(email)
    	    ,&(password)
    	    ,&(firstName)
    	    ,&(lastName)
    	    ,&(phoneNumber)
    	    ,&(city)
    	    ,&(adress)
    	    ,&(stateProvinceRegion)
    	    ,&(postalCode)
    	    ,&(userId)
    	    ,&(plBase64)
    	    ,&(authToken)
    	    ,&(shortCountry)
    	    ,&(countryId));
    
     
	lr_save_string(login, "login");
	lr_save_string(email, "email");
	lr_save_string(password, "password");
	lr_save_string(firstName, "firstName");
	lr_save_string(lastName, "lastName");
	lr_save_string(phoneNumber, "phoneNumber");
	lr_save_string(city, "city");
	lr_save_string(adress, "adress");
	lr_save_string(stateProvinceRegion, "stateProvinceRegion");
	lr_save_string(postalCode, "postalCode");
	lr_save_string(userId, "userId");
	lr_save_string(plBase64, "plBase64");
	lr_save_string(authToken, "authToken");
	lr_save_string(shortCountry, "shortCountry");
	lr_save_string(countryId, "countryId");
}


void getRandomCategoryAndProduct(char json[30000]){
	
	char colCategoriesStr[5];
	char colProductsOfCategoryStr[5];
	char randomCategoryStr[5];
	char randomProductStr[5];
	char categoryId[5];
	char categoryName[10];
	int colCategories;
	int colProductsOfCategory;
	char str1[15]="Active";
	char str2[15];
	
	lr_save_string(json, "json");
	
	 
	lr_eval_json ("Buffer={json}", "JsonObject=JSON_Param");
	
	colCategories = lr_json_find("JsonObject=JSON_Param","Value=.*","QueryString=$.[*].categoryId","SelectAll=Yes","UseRegExp=Yes","LAST");
	itoa(colCategories, colCategoriesStr, 10);
	lr_save_string(colCategoriesStr, "colCategories");
		
	while(strcmp (str1, str2)!=0){
		strcpy(str2, "");
		
		itoa(rand()%colCategories, randomCategoryStr, 10);
		lr_save_string(randomCategoryStr, "randomCategoryIdInJson");
		
		colProductsOfCategory = lr_json_find("JsonObject=JSON_Param","Value=.*","QueryString=$.[{randomCategoryIdInJson}].products[*].id","SelectAll=Yes","UseRegExp=Yes","LAST");
		itoa(colProductsOfCategory, colProductsOfCategoryStr, 10);
		lr_save_string(colProductsOfCategoryStr, "colProductsOfCategory");
		
		itoa(rand()%colProductsOfCategory, randomProductStr, 10);
		lr_save_string(randomProductStr, "randomProductIdInJson");

		lr_json_get_values("JsonObject=JSON_Param","ValueParam=categoryId","QueryString=$.[{randomCategoryIdInJson}].categoryId","LAST");
		lr_json_get_values("JsonObject=JSON_Param","ValueParam=categoryName","QueryString=$.[{randomCategoryIdInJson}].categoryName","LAST");
		lr_json_get_values("JsonObject=JSON_Param","ValueParam=productId","QueryString=$.[{randomCategoryIdInJson}].products[{randomProductIdInJson}].id","LAST");
		lr_json_get_values("JsonObject=JSON_Param","ValueParam=productName","QueryString=$.[{randomCategoryIdInJson}].products[{randomProductIdInJson}].productName","LAST");
		lr_json_get_values("JsonObject=JSON_Param","ValueParam=productPrice","QueryString=$.[{randomCategoryIdInJson}].products[{randomProductIdInJson}].price","LAST");
		lr_json_get_values("JsonObject=JSON_Param","ValueParam=productDescription","QueryString=$.[{randomCategoryIdInJson}].products[{randomProductIdInJson}].description","LAST");
		lr_json_get_values("JsonObject=JSON_Param","ValueParam=productStatus","QueryString=$.[{randomCategoryIdInJson}].products[{randomProductIdInJson}].productStatus","LAST");	
		
		strcpy(str2, lr_eval_string("{productStatus}"));
	}
	 
}

void productInCartAfterShop(char json[30000]) {
	int i;
    char iStr[5];
    int colProductInCart = 0;
    int result = 0;
	
	 
    lr_eval_json ("Buffer={jsonCart}", "JsonObject=jsonCart");
     
    colProductInCart = lr_json_find("JsonObject=jsonCart","Value=.*","QueryString=$.productsInCart[*].productId","NotFound=Continue","SelectAll=Yes","UseRegExp=Yes","LAST");
	 
    for (i = 0; i < colProductInCart; i++) {
		itoa(i, iStr, 10);
		lr_save_string(iStr, "productIdInCart");
		lr_json_get_values("JsonObject=jsonCart","ValueParam=productId_after","QueryString=$.productsInCart[{productIdInCart}].productId","LAST");
		lr_json_get_values("JsonObject=jsonCart","ValueParam=productName_after","QueryString=$.productsInCart[{productIdInCart}].productName","LAST");
		lr_json_get_values("JsonObject=jsonCart","ValueParam=price_after","QueryString=$.productsInCart[{productIdInCart}].price","LAST");
		lr_json_get_values("JsonObject=jsonCart","ValueParam=colorInt_after","QueryString=$.productsInCart[{productIdInCart}].color.code","LAST");
		 
		if ((strcmp(lr_eval_string("{productId}"), lr_eval_string("{productId_after}"))==0)&&
		    (strcmp(lr_eval_string("{productName}"), lr_eval_string("{productName_after}"))==0)&&
		    (strcmp(lr_eval_string("{productPrice}"), lr_eval_string("{price_after}"))==0)&&
		    (strcmp(lr_eval_string("{randomColorProductInt}"), lr_eval_string("{colorInt_after}"))==0)) {
			result = 1;
			break;
		}
	}
	 
	if (result == 0) {
    lr_error_message("Продукт не был добавлен в корзину");
    lr_abort();
    }
	
}



int getQuantityProductInCart(char json[30000]){
	int i;
	char iStr[5];
	int colProductInCart = 0;
	int quantity;
	char quantityStr[6];
	
	lr_save_string(json, "jsonCart");
	
	lr_eval_json ("Buffer={jsonCart}", "JsonObject=jsonCart");
	
	colProductInCart = lr_json_find("JsonObject=jsonCart","Value=.*","QueryString=$.productsInCart[*].productId","NotFound=Continue","SelectAll=Yes","UseRegExp=Yes","LAST");
	quantity = 0;
	for (i = 0; i < colProductInCart; i++) {
		itoa(i, iStr, 10);
		lr_save_string(iStr, "productIdInCart");
		lr_json_get_values("JsonObject=jsonCart","ValueParam=quantity","QueryString=$.productsInCart[{productIdInCart}].quantity","LAST");
		quantity = atoi(lr_eval_string("{quantity}")) + quantity;
	}
	return quantity;
}


int getColProductInOrdersList(char json[30000]){
	int colProduct;
	char colProductStr[5];
	
	lr_save_string(json, "json");
	
	lr_eval_json("Buffer={json}", "JsonObject=JSON_AllOrders");
	
	colProduct = lr_json_find("JsonObject=JSON_AllOrders","Value=.*","QueryString=$.OrderLines[*].Quantity", "NotFound=Continue", "SelectAll=Yes","UseRegExp=Yes","LAST");
	itoa(colProduct, colProductStr, 10);
	lr_save_string(colProductStr, "colProduct");
	return colProduct;
}


void getRandomOrderNumber(char json[30000], int colProduct){
	char randomOrderNumberStr[5];
	
	lr_save_string(json, "json");
	lr_eval_json("Buffer={json}", "JsonObject=JSON_AllOrders");
	
	itoa(rand()%colProduct, randomOrderNumberStr, 10);
	lr_save_string(randomOrderNumberStr, "randomOrderId");
	lr_json_get_values("JsonObject=JSON_AllOrders","ValueParam=randomOrderNumber","QueryString=$.OrderLines[{randomOrderId}].OrderNumber","LAST");
}


double getAllPriceProductInCart(char json[30000]){
	int i;
	char iStr[5];
	int colProductInCart = 0;
	double price;
	char priceStr[6];
	
	lr_save_string(json, "jsonCartAllPrice");
	
	lr_eval_json ("Buffer={jsonCartAllPrice}", "JsonObject=jsonCartAllPrice");
	
	colProductInCart = lr_json_find("JsonObject=jsonCartAllPrice","Value=.*","QueryString=$.productsInCart[*].productId","NotFound=Continue","SelectAll=Yes","UseRegExp=Yes","LAST");
	price = 0;
	for (i = 0; i < colProductInCart; i++) {
		itoa(i, iStr, 10);
		lr_save_string(iStr, "productIdInCart");
		lr_json_get_values("JsonObject=jsonCartAllPrice","ValueParam=price","QueryString=$.productsInCart[{productIdInCart}].price","LAST");
		lr_output_message("price preopr: %f", atof(lr_eval_string("{price}")));
		price = atof(lr_eval_string("{price}")) + price;
	}
	lr_output_message("price: %f", price);
	return price;
}


void getRandomColorProduct(char json[30000]){
	int colProductColors;
	char randomColorProductStr[10];	
	
	lr_save_string(json, "jsonProduct");
	
	lr_eval_json ("Buffer={jsonProduct}", "JsonObject=jsonProduct");
	colProductColors = lr_json_find("JsonObject=jsonProduct","Value=.*","QueryString=$.colors[*].code","NotFound=Continue","SelectAll=Yes","UseRegExp=Yes","LAST");
	
	itoa(rand()%colProductColors, randomColorProductStr, 10);
	lr_save_string(randomColorProductStr, "randomColorProduct");
	lr_json_get_values("JsonObject=jsonProduct","ValueParam=randomColorProductInt","QueryString=$.colors[{randomColorProduct}].code","LAST");
	lr_json_get_values("JsonObject=jsonProduct","ValueParam=randomColorProduct","QueryString=$.colors[{randomColorProduct}].name","LAST");
}


void getRandomProductInCartForDelete(char json[30000]){
	
	int colProductInCart;
	char colProductInCartStr[5];
	
	lr_save_string(json, "jsonCartForDelete");
	lr_eval_json ("Buffer={jsonCartForDelete}", "JsonObject=jsonCartForDelete");
	colProductInCart = lr_json_find("JsonObject=jsonCartForDelete","Value=.*","QueryString=$.productsInCart[*].productId","NotFound=Continue","SelectAll=Yes","UseRegExp=Yes","LAST");
	
	itoa(rand()%colProductInCart, colProductInCartStr, 10);
	lr_save_string(colProductInCartStr, "randomProductIdInJson");
	
	lr_json_get_values("JsonObject=jsonCartForDelete","ValueParam=productId_Delete","QueryString=$.productsInCart[{randomProductIdInJson}].productId","LAST");
	lr_json_get_values("JsonObject=jsonCartForDelete","ValueParam=productQuantity_Delete","QueryString=$.productsInCart[{randomProductIdInJson}].quantity","LAST");
	lr_json_get_values("JsonObject=jsonCartForDelete","ValueParam=productColorInt_Delete","QueryString=$.productsInCart[{randomProductIdInJson}].color.code","LAST");
	
}


 
void rewriteColProductIntoFile(char username[30], char colQuantity[5]){
	FILE *fp; 
	FILE *fp1;
	char row[800];
    char login[30];
    char result[800];
	
	while ((fp = fopen("..\\Outputfile\\userdata.dat", "r"))==0) {
		
	}
	
	while ((fp1 = fopen("..\\Outputfile\\userdata1.dat", "a"))==0) {
		
	}

	lr_save_string(colQuantity, "quantityIn");

    while (fgets(row, 800, fp) != 0) {
		sscanf(row,"%s	",login);

		if (strcmp (username, login)==0) {
			strcpy(result,"");
			strcpy(result, lr_eval_string("{login}	{email}	{password}	{firstName}	{lastName}	{phoneNumber}	{city}	{adress}	{stateProvinceRegion}	{postalCode}	{userId}	{plBase64}	{authToken}	{quantityIn}	{countOrder}	{inUse}	{shortCountry}	{country}\n"));
			fprintf(fp1,result);
		} else {
			fprintf(fp1,row);  
		}
    	
    }
	
    fclose(fp);
    fclose(fp1);
	while (-1 == remove("..\\Outputfile\\userdata.dat"));
	while (-1 == rename("..\\Outputfile\\userdata1.dat", "..\\Outputfile\\userdata.dat"));
	
}

 
void rewriteColProductAndOrderIntoFile(char username[30], char colOrder[10], char colQuantity[10]){
	FILE *fp; 
	FILE *fp1;
	char row[800];
    char login[30];
    char result[800];

	while ((fp = fopen("..\\Outputfile\\userdata.dat", "r"))==0) {
		
	}
	
	while ((fp1 = fopen("..\\Outputfile\\userdata1.dat", "a"))==0) {
		
	}

	lr_save_string(colOrder, "colOrderInOrder");
	lr_save_string(colQuantity, "quantityInOrder");
	
    while (fgets(row, 800, fp) != 0) {
		sscanf(row,"%s	",login);

		if (strcmp (username, login)==0) {
			strcpy(result,"");
			strcpy(result, lr_eval_string("{login}	{email}	{password}	{firstName}	{lastName}	{phoneNumber}	{city}	{adress}	{stateProvinceRegion}	{postalCode}	{userId}	{plBase64}	{authToken}	{quantityInOrder}	{colOrderInOrder}	{inUse}	{shortCountry}	{country}\n"));
			fprintf(fp1,result);
		} else {
			fprintf(fp1,row);  
		}
    	
    }
	
    fclose(fp);
    fclose(fp1);
	while (-1 == remove("..\\Outputfile\\userdata.dat"));
	while (-1 == rename("..\\Outputfile\\userdata1.dat", "..\\Outputfile\\userdata.dat"));
	
}



 
void rewriteInUseOn(char username[30]){
	FILE *fp; 
	FILE *fp1;
	char row[800];
    char login[30];
    char result[800];

	while ((fp = fopen("..\\Outputfile\\userdata.dat", "r"))==0) {
		
	}
	
	while ((fp1 = fopen("..\\Outputfile\\userdata1.dat", "a"))==0) {
		
	}
	
	lr_save_string("1", "inUseOn");
	
    while (fgets(row, 800, fp) != 0) {
		sscanf(row,"%s	",login);


		if (strcmp (username, login)==0) {
			strcpy(result,"");
			strcpy(result, lr_eval_string("{login}	{email}	{password}	{firstName}	{lastName}	{phoneNumber}	{city}	{adress}	{stateProvinceRegion}	{postalCode}	{userId}	{plBase64}	{authToken}	{quantityInCart}	{countOrder}	{inUseOn}	{shortCountry}	{country}\n"));
			fprintf(fp1,result);
		} else {
			fprintf(fp1,row);  
		}
    	
    }
	
    fclose(fp);
    fclose(fp1);
	
	while (-1 == remove("..\\Outputfile\\userdata.dat"));
	while (-1 == rename("..\\Outputfile\\userdata1.dat", "..\\Outputfile\\userdata.dat"));
	
}









void getRowFromFileOnLogin(char username[30]) {
	FILE *fp; 
	char row[800];
    char login[30];
    char result[800];

	while ((fp = fopen("..\\Outputfile\\userdata.dat", "r"))==0) {}
	
    while (fgets(row, 800, fp) != 0) {
		sscanf(row,"%s	",login);

		if (strcmp (username, login)==0) {
			break;
		}
    	
    }
	
    fclose(fp);
	lr_save_string(row, "RandomRowFromFile");
		
}


void getJsonForOrder(char json[10000]){
   int colProductInCart;
   char productIdStr[5];
   int productId = 0;
   char jsonForOrder[10000] = "";

	lr_save_string(json, "jsonCartForOrder");
    lr_eval_json("Buffer={jsonCartForOrder}", "JsonObject=jsonCartForOrder");
    colProductInCart = lr_json_find("JsonObject=jsonCartForOrder","Value=.*","QueryString=$.productsInCart[*].productId","NotFound=Continue","SelectAll=Yes","UseRegExp=Yes","LAST");
    
    strcat(jsonForOrder,"[");
    for (productId=0; productId < colProductInCart; productId++) {
    	itoa(productId, productIdStr, 10);
		lr_save_string(productIdStr, "productIdInJsonForOrder");
		
		lr_json_get_values("JsonObject=jsonCartForOrder","ValueParam=productId_Put","QueryString=$.productsInCart[{productIdInJsonForOrder}].productId","LAST");
		lr_json_get_values("JsonObject=jsonCartForOrder","ValueParam=productQuantity_Put","QueryString=$.productsInCart[{productIdInJsonForOrder}].quantity","LAST");
		lr_json_get_values("JsonObject=jsonCartForOrder","ValueParam=hexColor_Put","QueryString=$.productsInCart[{productIdInJsonForOrder}].color.code","LAST");
		
		strcat(jsonForOrder,"{\"hexColor\":");
		strcat(jsonForOrder,lr_eval_string("\"{hexColor_Put}\","));
		
		strcat(jsonForOrder,"\"productId\":");
		strcat(jsonForOrder,lr_eval_string("{productId_Put},"));
		
		strcat(jsonForOrder,"\"quantity\":");
		strcat(jsonForOrder,lr_eval_string("{productQuantity_Put}}"));
		
		if (productId != (colProductInCart - 1)) {
    		strcat(jsonForOrder,",");
    	}
    	 
    }
    strcat(jsonForOrder,"]");
    lr_save_string(jsonForOrder, "jsonForOrder");


}
# 11 "globals.h" 2


 
 


# 3 "c:\\users\\user\\documents\\vugen\\scripts\\uc3_addproducttoshopcart\\\\combined_UC3_AddProductToShopCart.c" 2

# 1 "vuser_init.c" 1
vuser_init()
{
	return 0;
}
# 4 "c:\\users\\user\\documents\\vugen\\scripts\\uc3_addproducttoshopcart\\\\combined_UC3_AddProductToShopCart.c" 2

# 1 "Action.c" 1
Action()
{

    
	readRowFromParameters(lr_eval_string("{randomRowFromFile}"));	
    
    
    lr_start_transaction("UC3_AddProductToShopCart");

    
    
    lr_start_transaction("Goto_HomePage");

    web_set_sockets_option("SSL_VERSION", "2&3");
    web_set_user("{login}", "{password}", "{domain}:80");
    web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN={domain}");
    
    web_reg_find("Text=\"parameters\"","LAST");
    web_reg_find("Text=\"parameterName\"","LAST");
    
    web_url("ALL", 
        "URL={protocol}://{host}/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t3.inf", 
        "Mode=HTML", 
        "LAST");
    
    lr_output_message(">> ��� ��������� ������� ��������");
    
    web_add_cookie("_gat=1; DOMAIN={domain}");
    web_add_header("Origin", "{protocol}://{host}");
    web_add_header("SOAPAction", "com.advantage.online.store.accountserviceGetAccountConfigurationRequest");
    web_add_header("X-Requested-With", "XMLHttpRequest");

    web_reg_find("Text=numberOfFailedLoginAttemptsBeforeBlocking","LAST");
    
    web_custom_request("GetAccountConfigurationRequest", 
        "URL={protocol}://{host}/accountservice/ws/GetAccountConfigurationRequest", 
        "Method=POST", 
        "Resource=0", 
        "RecContentType=text/xml", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t4.inf", 
        "Mode=HTML", 
        "EncType=text/xml; charset=UTF-8", 
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
        "LAST");
    
    lr_output_message(">> ������������� ������������ ������� ��������");

    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.0.1708954185.60.0.0; DOMAIN={domain}");

     
    web_set_max_html_param_len("9999999");
    web_reg_save_param("fullresponse", "LB=\r\n\r\n", "RB=", "LAST");
    
     
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", "LAST");
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"","LAST");
    web_reg_find("Text=\"categoryName\":\"TABLETS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"MICE\"","LAST");
    
    web_url("categories",
        "URL={protocol}://{host}/catalog/api/v1/categories", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t6.inf", 
        "Mode=HTML", 
        "LAST");
    
    lr_output_message(">> ��� ��������� ������� �������� �� ��������");
    
     
    getRandomCategoryAndProduct(lr_eval_string("{fullresponse}"));
    
    lr_output_message(">> �������� ������� json'a");
    
     
    web_reg_find("Text=\"promotionHeader\"","LAST");
    web_reg_find("Text=\"promotionSubHeader\"","LAST");
    
    web_url("dealOfTheDay", 
        "URL={protocol}://{host}/catalog/api/v1/deals/search?dealOfTheDay=true", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t8.inf", 
        "Mode=HTML", 
        "LAST");

    lr_output_message(">> ������� ����� �� ����. ����������� �� ������� ��������");
    
     
    web_reg_find("Text=\"productName\"","LAST");
    web_reg_find("Text=\"description\"","LAST");
    
    web_url("popularProducts", 
        "URL={protocol}://{host}/app/tempFiles/popularProducts.json", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t22.inf", 
        "Mode=HTML", 
        "LAST");
        
    lr_output_message(">> �������� ���������� ������ �� ������� ��������");

    lr_end_transaction("Goto_HomePage",2);
    
    
    lr_think_time(1);
    

    lr_start_transaction("Entry_AuthenticateData");

    web_add_auto_header("Origin", "{protocol}://{host}");
    web_add_auto_header("SOAPAction", "com.advantage.online.store.accountserviceAccountLoginRequest");
    web_add_auto_header("X-Requested-With", "XMLHttpRequest");
    
     
    web_reg_save_param_xpath("ParamName=sessionId","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:sessionId[1]/text()[1]","ReturnXml=No","SEARCH_FILTERS","Scope=Body","LAST");
     
    web_reg_save_param_xpath("ParamName=userId","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:userId[1]/text()[1]","ReturnXml=No","SEARCH_FILTERS","Scope=Body","LAST");
     
    web_reg_save_param_xpath("ParamName=loginPasswordBase64","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:t_authorization[1]/text()[1]","ReturnXml=No","SEARCH_FILTERS","Scope=Body","LAST");
    
     
    web_reg_find("Text=Login Successful","LAST");
    
    web_custom_request("AccountLoginRequest", 
        "URL={protocol}://{host}/accountservice/ws/AccountLoginRequest", 
        "Method=POST", 
        "Resource=0", 
        "RecContentType=text/xml", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t11.inf", 
        "Mode=HTML", 
        "EncType=text/xml; charset=UTF-8", 
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>{password}</loginPassword><loginUser>{login}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
        "LAST");
    
    lr_output_message(">> ���� � ������� ������� ��������");
    
    web_set_sockets_option("INITIAL_AUTH", "BASIC");
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.1.1708954254.60.0.0; DOMAIN={domain}");
    (web_remove_auto_header("Origin", "ImplicitGen=Yes", "LAST"));
    (web_remove_auto_header("SOAPAction", "ImplicitGen=Yes", "LAST"));
    (web_remove_auto_header("X-Requested-With", "ImplicitGen=Yes", "LAST"));
    
     
    web_reg_find("Text=\"userId\":{userId}","LAST");
    
    web_url("cartsBefore",
        "URL={protocol}://{host}/order/api/v1/carts/{userId}",
        "Resource=0",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t12.inf",
        "Mode=HTML",
        "LAST");
    
    lr_output_message(">> ������ �� ������� ������������ ��������");
    
    lr_end_transaction("Entry_AuthenticateData",2);

    
    

    lr_think_time(1);
    
    
    
    

    lr_start_transaction("Goto_CategoryPage");
    
     
    web_reg_find("Text=\"categoryName\":\"{categoryName}\"","LAST");

    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t13.inf", 
        "Mode=HTML", 
        "LAST");
    
     
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", "LAST");
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"","LAST");
    web_reg_find("Text=\"categoryName\":\"TABLETS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"MICE\"","LAST");
    
    web_url("attributes", 
        "URL={protocol}://{host}/catalog/api/v1/categories/attributes", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t14.inf", 
        "Mode=HTML", 
        "LAST");

    lr_end_transaction("Goto_CategoryPage",2);
    
    
    
    
    
    lr_think_time(1);
    
    
    
    
    lr_start_transaction("Goto_ProductPage");
    
    web_reg_find("Text=\"productId\":{productId}","LAST");
    web_reg_find("Text=\"categoryId\":{categoryId}","LAST");
    web_reg_find("Text=\"productName\":\"{productName}\"","LAST");
    web_reg_find("Text=\"price\":{productPrice}","LAST");
    
     
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonProduct", "LB=\r\n\r\n", "RB=", "LAST");
    
    web_url("getProductOnId", 
        "URL={protocol}://{host}/catalog/api/v1/products/{productId}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t16.inf", 
        "Mode=HTML", 
        "LAST");
    
    getRandomColorProduct(lr_eval_string("{jsonProduct}"));
    
     
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", "LAST");
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"","LAST");
    web_reg_find("Text=\"categoryName\":\"TABLETS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"MICE\"","LAST");
    
    web_url("all_data", 
        "URL={protocol}://{host}/catalog/api/v1/categories/all_data", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t17.inf", 
        "Mode=HTML", 
        "LAST");
    
    web_reg_find("Text=\"productName\":\"{productName}\"","LAST");
    web_reg_find("Text=\"categoryName\":\"{categoryName}\"","LAST");
    
    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t18.inf", 
        "Mode=HTML", 
        "LAST");
    
    web_reg_find("Text=image section","LAST");
    
    web_url("product-page", 
        "URL={protocol}://{host}/app/views/product-page.html", 
        "Resource=0", 
        "RecContentType=text/html", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t19.inf", 
        "Mode=HTML", 
        "LAST");

    lr_end_transaction("Goto_ProductPage",2);
    
    
    
    
    
    lr_think_time(1);
    
    
    
    

    lr_start_transaction("Add_ProductToShopCart");
        
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.1.1708954305.9.0.0; DOMAIN={domain}");
    web_add_header("Origin", "{protocol}://{host}");
    
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonCart", "LB=\r\n\r\n", "RB=", "LAST");
    
     
    web_reg_find("Text=\"userId\":{userId}","LAST");
    
    web_submit_data("cartsAfter",
        "Action={protocol}://{host}/order/api/v1/carts/{userId}/product/{productId}/color/{randomColorProductInt}?quantity={randomQuantity}",
        "Method=POST",
        "EncType=",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t20.inf",
        "Mode=HTML",
        "ITEMDATA",
        "Name=sessionId", "Value={sessionId}", "ENDITEM",
        "LAST");
    
    productInCartAfterShop(lr_eval_string("{jsonCart}"));
    
    lr_end_transaction("Add_ProductToShopCart",2);
    
    
    
    
    lr_think_time(1);
    
    
    
    
    
     
    
    
    
    
    
    
	lr_start_transaction("Goto_CategoryPage");
    
     
    web_reg_find("Text=\"categoryName\":\"{categoryName}\"","LAST");

    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t13.inf", 
        "Mode=HTML", 
        "LAST");
    
     
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", "LAST");
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"","LAST");
    web_reg_find("Text=\"categoryName\":\"TABLETS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"MICE\"","LAST");
    
    web_url("attributes", 
        "URL={protocol}://{host}/catalog/api/v1/categories/attributes", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t14.inf", 
        "Mode=HTML", 
        "LAST");

    lr_end_transaction("Goto_CategoryPage",2);
    
    
    
    
    
    lr_think_time(1);
    
    
    
    
    lr_start_transaction("Goto_ProductPage");
    
    web_reg_find("Text=\"productId\":{productId}","LAST");
    web_reg_find("Text=\"categoryId\":{categoryId}","LAST");
    web_reg_find("Text=\"productName\":\"{productName}\"","LAST");
    web_reg_find("Text=\"price\":{productPrice}","LAST");
    
     
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonProduct", "LB=\r\n\r\n", "RB=", "LAST");
    
    web_url("getProductOnId", 
        "URL={protocol}://{host}/catalog/api/v1/products/{productId}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t16.inf", 
        "Mode=HTML", 
        "LAST");
    
    getRandomColorProduct(lr_eval_string("{jsonProduct}"));
    
     
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", "LAST");
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"","LAST");
    web_reg_find("Text=\"categoryName\":\"TABLETS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"MICE\"","LAST");
    
    web_url("all_data", 
        "URL={protocol}://{host}/catalog/api/v1/categories/all_data", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t17.inf", 
        "Mode=HTML", 
        "LAST");
    
    web_reg_find("Text=\"productName\":\"{productName}\"","LAST");
    web_reg_find("Text=\"categoryName\":\"{categoryName}\"","LAST");
    
    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t18.inf", 
        "Mode=HTML", 
        "LAST");
    
    web_reg_find("Text=image section","LAST");
    
    web_url("product-page", 
        "URL={protocol}://{host}/app/views/product-page.html", 
        "Resource=0", 
        "RecContentType=text/html", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t19.inf", 
        "Mode=HTML", 
        "LAST");

    lr_end_transaction("Goto_ProductPage",2);
    
    
    
    
    
    lr_think_time(1);
    
    
    
    

    lr_start_transaction("Add_ProductToShopCart");
        
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.1.1708954305.9.0.0; DOMAIN={domain}");
    web_add_header("Origin", "{protocol}://{host}");
    
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonCart", "LB=\r\n\r\n", "RB=", "LAST");
    
     
    web_reg_find("Text=\"userId\":{userId}","LAST");
    
    web_submit_data("cartsAfter",
        "Action={protocol}://{host}/order/api/v1/carts/{userId}/product/{productId}/color/{randomColorProductInt}?quantity={randomQuantity}",
        "Method=POST",
        "EncType=",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t20.inf",
        "Mode=HTML",
        "ITEMDATA",
        "Name=sessionId", "Value={sessionId}", "ENDITEM",
        "LAST");
    
    productInCartAfterShop(lr_eval_string("{jsonCart}"));
    
    lr_end_transaction("Add_ProductToShopCart",2);
    
    
    
    
    lr_think_time(1);
    
    
    
     
    
    
    
    
    
    
    
    
    
    
	 
    
    
    
    
    
    
	lr_start_transaction("Goto_CategoryPage");
    
     
    web_reg_find("Text=\"categoryName\":\"{categoryName}\"","LAST");

    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t13.inf", 
        "Mode=HTML", 
        "LAST");
    
     
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", "LAST");
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"","LAST");
    web_reg_find("Text=\"categoryName\":\"TABLETS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"MICE\"","LAST");
    
    web_url("attributes", 
        "URL={protocol}://{host}/catalog/api/v1/categories/attributes", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t14.inf", 
        "Mode=HTML", 
        "LAST");

    lr_end_transaction("Goto_CategoryPage",2);
    
    
    
    
    
    lr_think_time(1);
    
    
    
    
    lr_start_transaction("Goto_ProductPage");
    
    web_reg_find("Text=\"productId\":{productId}","LAST");
    web_reg_find("Text=\"categoryId\":{categoryId}","LAST");
    web_reg_find("Text=\"productName\":\"{productName}\"","LAST");
    web_reg_find("Text=\"price\":{productPrice}","LAST");
    
     
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonProduct", "LB=\r\n\r\n", "RB=", "LAST");
    
    web_url("getProductOnId", 
        "URL={protocol}://{host}/catalog/api/v1/products/{productId}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t16.inf", 
        "Mode=HTML", 
        "LAST");
    
    getRandomColorProduct(lr_eval_string("{jsonProduct}"));
    
     
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", "LAST");
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"","LAST");
    web_reg_find("Text=\"categoryName\":\"TABLETS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"","LAST");
    web_reg_find("Text=\"categoryName\":\"MICE\"","LAST");
    
    web_url("all_data", 
        "URL={protocol}://{host}/catalog/api/v1/categories/all_data", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t17.inf", 
        "Mode=HTML", 
        "LAST");
    
    web_reg_find("Text=\"productName\":\"{productName}\"","LAST");
    web_reg_find("Text=\"categoryName\":\"{categoryName}\"","LAST");
    
    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t18.inf", 
        "Mode=HTML", 
        "LAST");
    
    web_reg_find("Text=image section","LAST");
    
    web_url("product-page", 
        "URL={protocol}://{host}/app/views/product-page.html", 
        "Resource=0", 
        "RecContentType=text/html", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t19.inf", 
        "Mode=HTML", 
        "LAST");

    lr_end_transaction("Goto_ProductPage",2);
    
    
    
    
    
    lr_think_time(1);
    
    
    
    

    lr_start_transaction("Add_ProductToShopCart");
        
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.1.1708954305.9.0.0; DOMAIN={domain}");
    web_add_header("Origin", "{protocol}://{host}");
    
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonCart", "LB=\r\n\r\n", "RB=", "LAST");
    
     
    web_reg_find("Text=\"userId\":{userId}","LAST");
    
    web_submit_data("cartsAfter",
        "Action={protocol}://{host}/order/api/v1/carts/{userId}/product/{productId}/color/{randomColorProductInt}?quantity={randomQuantity}",
        "Method=POST",
        "EncType=",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t20.inf",
        "Mode=HTML",
        "ITEMDATA",
        "Name=sessionId", "Value={sessionId}", "ENDITEM",
        "LAST");
    
    productInCartAfterShop(lr_eval_string("{jsonCart}"));
    
    lr_end_transaction("Add_ProductToShopCart",2);
    
    
    
    
    lr_think_time(1);
    
    
    
     
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    lr_start_transaction("Logout");

    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1708954120.7.1.1708954391.0.0.0; DOMAIN={domain}");
    web_add_header("SOAPAction", "com.advantage.online.store.accountserviceAccountLogoutRequest");
    web_add_header("X-Requested-With", "XMLHttpRequest");

     
    web_reg_find("Text=Logout Successful","LAST");
    
    web_custom_request("AccountLogoutRequest",
        "URL={protocol}://{host}/accountservice/ws/AccountLogoutRequest",
        "Method=POST",
        "Resource=0",
        "RecContentType=text/xml",
        "Referer={protocol}://{host}/",
        "Snapshot=t24.inf",
        "Mode=HTML",
        "EncType=text/xml; charset=UTF-8",
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>{userId}</loginUser><base64Token>Basic {loginPasswordBase64}</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>",
        "LAST");

    lr_end_transaction("Logout",2);

    
    
    lr_end_transaction("UC3_AddProductToShopCart",2);

    return 0;
}
# 5 "c:\\users\\user\\documents\\vugen\\scripts\\uc3_addproducttoshopcart\\\\combined_UC3_AddProductToShopCart.c" 2

# 1 "vuser_end.c" 1
vuser_end()
{
	return 0;
}
# 6 "c:\\users\\user\\documents\\vugen\\scripts\\uc3_addproducttoshopcart\\\\combined_UC3_AddProductToShopCart.c" 2

