Gobang:Main.c Gobang.c
	gcc $^ -o $@

.PHONY:clean
clean:
	rm -f Gobang
