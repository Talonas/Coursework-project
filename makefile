CAT_MAP     = make -C prot_cat_map
BAKERS_MAP  = make -C prot_bakers_map
GLOBAL      = make -C prot_global_var

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

clean:
	$(CAT_MAP) clean
	$(BAKERS_MAP) clean
	$(GLOBAL) clean
