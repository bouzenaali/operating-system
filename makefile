CC     = @/usr/bin/gcc
CFLAGS = -Wall -g -std=c99
ECHO   = @echo

all: clean directories LAB1 LAB2 LAB2extra LAB3 LAB4 LAB5 LAB6 TEST complete

clean:
	@rm -rf bin
	$(ECHO) "All binaries removed"

directories:
	@mkdir -p bin
	$(ECHO) "Output directories created"

LAB1: directories
	$(CC) $(CFLAGS) "LAB1/avg.c" -o bin/avg
	$(ECHO) "Build avg {LAB1}"
	$(CC) $(CFLAGS) "LAB1/display.c" -o bin/display
	$(ECHO) "Build display {LAB1}"
	$(CC) $(CFLAGS) "LAB1/example.c" -o bin/example
	$(ECHO) "Build example {LAB1}"
	$(CC) $(CFLAGS) "LAB1/exo5I.c" -o bin/exo5I
	$(ECHO) "Build exo5I {LAB1}"
	$(CC) $(CFLAGS) "LAB1/exo5II.c" -o bin/exo5II
	$(ECHO) "Build exo5II {LAB1}"
	$(CC) $(CFLAGS) "LAB1/fork.c" -o bin/fork
	$(ECHO) "Build fork {LAB1}"

LAB2: directories 
	$(CC) $(CFLAGS) "LAB2/exo1.c" -o bin/exo1
	$(ECHO) "Build  exo1 {LAB2}"
	$(CC) $(CFLAGS) "LAB2/q1_extra.c" -o bin/q1_extra
	$(ECHO) "Build  q1_extra {LAB2}"

LAB2extra: directories
	$(CC) $(CFLAGS) "LAB2extra/q1.c" -o bin/q1
	$(ECHO) "Build q1 {LAB2extra}"
	$(CC) $(CFLAGS) "LAB2extra/q2.c" -o bin/q2
	$(ECHO) "Build q2 {LAB2extra}"

LAB3: directories 
	$(CC) $(CFLAGS) "LAB3/exo1.c" -o bin/exo1
	$(ECHO) "Build exo1 {LAB3}"

LAB4: directories
	$(CC) $(CFLAGS) "LAB4/program.c" -o bin/program
	$(ECHO) "Build program {LAB4}"
	$(CC) $(CFLAGS) "LAB4/programv2.c" -o bin/programv2
	$(ECHO) "Build programv2 {LAB4}"

LAB5: directories
	$(CC) $(CFLAGS) "LAB5/exo1.c" -o bin/exo1
	$(ECHO) "Build exo1 {LAB5}"
	$(CC) $(CFLAGS) "LAB5/exo2.c" -o bin/exo2
	$(ECHO) "Build exo2 {LAB5}"

LAB6: directories
	$(CC) $(CFLAGS) "LAB6/program.c" -o bin/program6 -pthread
	$(ECHO) "Build program6 {LAB6}"

TEST: directories
	$(CC) $(CFLAGS) "TP TEST/exo2.c" -o bin/test1
	$(ECHO) "Build test1 {TEST TP}"

	$(CC) $(CFLAGS) "TP TEST/exo3.c" -o bin/test2
	$(ECHO) "Build test2 {TEST TP}"

complete:
	$(ECHO) "All binaries build to directory 'bin/'"

