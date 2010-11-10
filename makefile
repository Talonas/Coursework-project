cat_map:
	make -C prot_cat_map compile

bakers_map:
	make -C prot_bakers_map compile

global:
	make -C prot_global_var compile

clean:
	make -C prot_cat_map clean
	make -C prot_bakers_map clean
	make -C prot_global_var clean
