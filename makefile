ARGS = make -C

CAT_MAP     = ${ARGS} prot_cat_map
BAKERS_MAP  = ${ARGS} prot_bakers_map
GLOBAL      = ${ARGS} prot_global_var

compile:
	$(CAT_MAP) compile
	$(BAKERS_MAP) compile
	$(GLOBAL) compile

cat_map:
	$(CAT_MAP) compile

bakers_map:
	$(BAKERS_MAP) compile

global:
	$(GLOBAL) compile

clean_cat_map:
	${CAT_MAP} clean

clean_bakers_map:
	${BAKERS_MAP} clean

clean_global:
	$(GLOBAL) clean

clean:
	$(CAT_MAP) clean
	$(BAKERS_MAP) clean
	$(GLOBAL) clean
