SHELL = /bin/sh

LIB_HEADERS_INSTALL_DIR = /usr/local/include/la


# ************           install          **************
.PHONY: install
 install:
	# copy headers
	mkdir -p $(LIB_HEADERS_INSTALL_DIR)
	cp -a ./src/*.h $(LIB_HEADERS_INSTALL_DIR)


# ************       clean and purge      **************
.PHONY: clean
clean: 
	-rm -f ./c/*~
	-rm -f ./c/*#
	-rm -f ./python/*~
	-rm -f ./python/*#
	-rm -f ./test/*~
	-rm -f ./test/*#
	-rm -f test/headers_sanity
	-rm -f test/lav3
	-rm -f *~
	-rm -f *#

.PHONY: clean-perf-stats
clean-perf-stats: 
	-rm -f ./test/perf-stats-2009*

