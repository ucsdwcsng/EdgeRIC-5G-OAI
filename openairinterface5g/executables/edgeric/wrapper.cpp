#include "edgeric.h"
#include "wrapper.h"
#include <limits.h>  // For INT_MAX
#include <float.h>   // For FLT_MAX



struct erc{
    void *obj;
};

EdgeRIC *ric_create()
{
    EdgeRIC *r;
    edgeric *obj;

    r = (typeof(r))malloc(sizeof(*r));
    obj = new edgeric();
    r -> obj = obj;
    return r;
}

void ric_destroy(EdgeRIC *r)
{
    if(r == NULL)
        return;
    delete static_cast<edgeric *>(r->obj);
    free(r);
}

void ric_setTTI(EdgeRIC *r, int tti_count)
{
    edgeric *obj;

	if (r == NULL)
		return;

	obj = static_cast<edgeric *>(r->obj);
	obj->setTTI(tti_count);
}

void ric_printmyvariables(EdgeRIC *r)
{
    edgeric *obj;

	if (r == NULL)
		return;

	obj = static_cast<edgeric *>(r->obj);
	obj->printmyvariables();
}

void ric_init(EdgeRIC *r)
{
    edgeric *obj;

	if (r == NULL)
		return;

	obj = static_cast<edgeric *>(r->obj);
	obj->init();
}

void ric_set_cqi(EdgeRIC *r, uint16_t rnti, float cqi)
{
    edgeric *obj;

	if (r == NULL)
		return;

	obj = static_cast<edgeric *>(r->obj);
	obj->set_cqi(rnti, cqi);
}

void ric_set_snr(EdgeRIC *r, uint16_t rnti, float snr)
{
    edgeric *obj;

	if (r == NULL)
		return;

	obj = static_cast<edgeric *>(r->obj);
	obj->set_snr(rnti, snr);
}

void ric_set_ul_buffer(EdgeRIC *r, uint16_t rnti, uint32_t ul_buffer)
{
    edgeric *obj;

	if (r == NULL)
		return;

	obj = static_cast<edgeric *>(r->obj);
	obj->set_ul_buffer(rnti, ul_buffer);
}

void ric_set_dl_buffer(EdgeRIC *r, uint16_t rnti, uint32_t dl_buffer)
{
    edgeric *obj;

	if (r == NULL)
		return;

	obj = static_cast<edgeric *>(r->obj);
	obj->set_dl_buffer(rnti, dl_buffer);
}

void ric_set_tx_bytes(EdgeRIC *r, uint16_t rnti, float tbs)
{
    edgeric *obj;

	if (r == NULL)
		return;

	obj = static_cast<edgeric *>(r->obj);
	obj->set_tx_bytes(rnti, tbs);
}

void ric_set_rx_bytes(EdgeRIC *r, uint16_t rnti, float tbs)
{
    edgeric *obj;

	if (r == NULL)
		return;

	obj = static_cast<edgeric *>(r->obj);
	obj->set_rx_bytes(rnti, tbs);
}

void ric_set_dl_tbs(EdgeRIC *r, uint16_t rnti, float tbs)
{
    edgeric *obj;

	if (r == NULL)
		return;

	obj = static_cast<edgeric *>(r->obj);
	obj->set_dl_tbs(rnti, tbs);
}

void ric_send_to_er(EdgeRIC *r)
{
    edgeric *obj;

	if (r == NULL)
		return;

	obj = static_cast<edgeric *>(r->obj);
	obj->send_to_er(); 

}

void ric_get_weights_from_er(EdgeRIC *r)
{
    edgeric *obj;

	if (r == NULL)
		return;

	obj = static_cast<edgeric *>(r->obj);
	obj->get_weights_from_er();
}

void ric_get_mcs_from_er(EdgeRIC *r)
{
    edgeric *obj;

	if (r == NULL)
		return;

	obj = static_cast<edgeric *>(r->obj);
	obj->get_mcs_from_er();
}



float ric_get_weights(EdgeRIC *r, uint16_t rnti)
{
    edgeric *obj;

	if (r == NULL)
		return 0;

	obj = static_cast<edgeric *>(r->obj);
    if((obj->get_weights(rnti)).has_value()){
        //return obj->get_weights(rnti);
		//auto result = obj -> get_weights(rnti);
		//printf("Weights:%f\n", obj->get_weights(rnti).value());
		return obj->get_weights(rnti).value();
    }
    else
        return FLT_MAX;
}

 int ric_get_mcs(EdgeRIC *r, uint16_t rnti)
{
    edgeric *obj;
	//printf("hiiiiiii from wrapperfor rnti %d\n", rnti);

	if (r == NULL)
		return 0;

	obj = static_cast<edgeric *>(r->obj);

	 if((obj->get_mcs(rnti)).has_value()){
        //return obj->get_weights(rnti);
		//auto result = obj -> get_weights(rnti);
		return obj->get_mcs(rnti).value();
    }
    else
        return INT_MAX;
}

