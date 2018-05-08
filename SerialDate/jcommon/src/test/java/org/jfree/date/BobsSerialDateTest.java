package org.jfree.date;

import junit.framework.TestCase;
import org.jfree.date.*;
import static org.junit.jupiter.api.Assertions.*;
import static org.jfree.date.SerialDate.*;

import java.util.*;

public class BobsSerialDateTest extends TestCase {
    public BobsSerialDateTest(final String name) {
        super(name);
    }

    public void testIsValidWeekdayCode() throws Exception {
        for (int day = 1; day <= 7; day++)
            assertTrue(isValidWeekdayCode(day));
        assertFalse(isValidWeekdayCode(0));
        assertFalse(isValidWeekdayCode(8));
    }

    public void testStringToWeekdayCode() throws Exception {
        assertEquals(-1, stringToWeekdayCode("Hello"));
        assertEquals(MONDAY, stringToWeekdayCode("Monday"));
        assertEquals(MONDAY, stringToWeekdayCode("Mon"));
// todo        assertEquals(MONDAY, stringToWeekdayCode("monday"));
//        assertEquals(MONDAY, stringToWeekdayCode("MONDAY"));
//        assertEquals(MONDAY, stringToWeekdayCode("mon"));
    }
}