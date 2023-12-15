DEPDIR := .deps
$(shell mkdir -p $(DEPDIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

$(DEPDIR)/%.d: ;
%.o: $(DEPDIR)/%.d

include $(wildcard $(patsubst %,$(DEPDIR)/%.d,$(basename $(SOURCES))))

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm -lsqlite3
SRCDIR = src
OBJDIR = obj
INCLUDEDIR = include
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))
EXECUTABLE = linux_binary

HEADERS = $(wildcard $(INCLUDEDIR)/*.h)

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) $^ -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(EXECUTABLE) $(DEPDIR)
