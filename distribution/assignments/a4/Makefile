all: assign4.html

%.json: %.toml
	python3 ../../admin/toml2json.py < $< > $@

%.html: %.md
	pandoc -o $@ $<
