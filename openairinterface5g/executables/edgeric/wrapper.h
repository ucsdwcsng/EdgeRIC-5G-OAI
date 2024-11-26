#ifdef __cplusplus
extern "C" {
#endif
struct erc;
typedef struct erc EdgeRIC;

EdgeRIC *ric_create();
void ric_destroy(EdgeRIC *r);

void ric_setTTI(EdgeRIC *r, int tti_count);
void ric_printmyvariables(EdgeRIC *r);
void ric_init(EdgeRIC *r);

void ric_set_cqi(EdgeRIC *r, uint16_t rnti, float cqi);
void ric_set_snr(EdgeRIC *r, uint16_t rnti, float snr);
void ric_set_ul_buffer(EdgeRIC *r, uint16_t rnti, uint32_t ul_buffer);
void ric_set_dl_buffer(EdgeRIC *r, uint16_t rnti, uint32_t dl_buffer);
void ric_set_tx_bytes(EdgeRIC *r, uint16_t rnti, float tbs);
void ric_set_rx_bytes(EdgeRIC *r, uint16_t rnti, float tbs);
void ric_set_dl_tbs(EdgeRIC *r, uint16_t rnti, float tbs);

//////////////////////////////////// ZMQ function to send RT-E2 Report 
void ric_send_to_er(EdgeRIC *r);

//////////////////////////////////// ZMQ function to receive RT-E2 Policy - called at end of slot
void ric_get_weights_from_er(EdgeRIC *r);
void ric_get_mcs_from_er(EdgeRIC *r);

//////////////////////////////////// Static getters - sets the control actions - called at slot beginning
//float ric_get_weights(EdgeRIC *r, int );
float ric_get_weights(EdgeRIC *r, uint16_t rnti);
int ric_get_mcs(EdgeRIC *r, uint16_t rnti);



extern EdgeRIC* agent;
extern int tti_counter;
#ifdef __cplusplus
}
#endif