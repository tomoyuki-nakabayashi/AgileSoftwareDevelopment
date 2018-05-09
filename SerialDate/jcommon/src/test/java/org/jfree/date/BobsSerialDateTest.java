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
        assertEquals(MONDAY, stringToWeekdayCode("monday"));
        assertEquals(MONDAY, stringToWeekdayCode("MONDAY"));
        assertEquals(MONDAY, stringToWeekdayCode("mon"));
    }

    public void testWeekdayCodeToString() throws Exception {
        assertEquals("Sunday", weekdayCodeToString(SUNDAY));
        assertEquals("Monday", weekdayCodeToString(MONDAY));
        assertEquals("Tuesday", weekdayCodeToString(TUESDAY));
        assertEquals("Wednesday", weekdayCodeToString(WEDNESDAY));
        assertEquals("Thursday", weekdayCodeToString(THURSDAY));
        assertEquals("Friday", weekdayCodeToString(FRIDAY));
        assertEquals("Saturday", weekdayCodeToString(SATURDAY));
    }

    public void testIsValidMonthCode() throws Exception {
        for (int i = 1; i <= 12; i++)
            assertTrue(isValidMonthCode(i));
        assertFalse(isValidMonthCode(0));
        assertFalse(isValidMonthCode(13));
    }

    public void testMonthToQuarter() throws Exception {
        assertEquals(1, monthCodeToQuarter(JANUARY));
        assertEquals(1, monthCodeToQuarter(FEBRUARY));
        assertEquals(1, monthCodeToQuarter(MARCH));
        assertEquals(2, monthCodeToQuarter(APRIL));
        assertEquals(2, monthCodeToQuarter(MAY));
        assertEquals(2, monthCodeToQuarter(JUNE));
        assertEquals(3, monthCodeToQuarter(JULY));
        assertEquals(3, monthCodeToQuarter(AUGUST));
        assertEquals(3, monthCodeToQuarter(SEPTEMBER));
        assertEquals(4, monthCodeToQuarter(OCTOBER));
        assertEquals(4, monthCodeToQuarter(NOVEMBER));
        assertEquals(4, monthCodeToQuarter(DECEMBER));

        try {
            monthCodeToQuarter(-1);
            fail("Invalid Month Code should throw exception");
        } catch (IllegalArgumentException e) {
        }
    }

    public void testMonthCodeToString() throws Exception {
        assertEquals("January", monthCodeToString(JANUARY));
        assertEquals("February", monthCodeToString(FEBRUARY));
        assertEquals("March", monthCodeToString(MARCH));
        assertEquals("April", monthCodeToString(APRIL));
        assertEquals("May", monthCodeToString(MAY));
        assertEquals("June", monthCodeToString(JUNE));
        assertEquals("July", monthCodeToString(JULY));
        assertEquals("August", monthCodeToString(AUGUST));
        assertEquals("September", monthCodeToString(SEPTEMBER));
        assertEquals("October", monthCodeToString(OCTOBER));
        assertEquals("November", monthCodeToString(NOVEMBER));
        assertEquals("December", monthCodeToString(DECEMBER));

        assertEquals("Jan", monthCodeToString(JANUARY, true));
        assertEquals("Feb", monthCodeToString(FEBRUARY, true));
        assertEquals("Mar", monthCodeToString(MARCH, true));
        assertEquals("Apr", monthCodeToString(APRIL, true));
        assertEquals("May", monthCodeToString(MAY, true));
        assertEquals("Jun", monthCodeToString(JUNE, true));
        assertEquals("Jul", monthCodeToString(JULY, true));
        assertEquals("Aug", monthCodeToString(AUGUST, true));
        assertEquals("Sep", monthCodeToString(SEPTEMBER, true));
        assertEquals("Oct", monthCodeToString(OCTOBER, true));
        assertEquals("Nov", monthCodeToString(NOVEMBER, true));
        assertEquals("Dec", monthCodeToString(DECEMBER, true));

        try {
            monthCodeToString(-1);
            fail("Invalid month code should throw exception");
        } catch (IllegalArgumentException e) {}
    }

    public void testStringToMonthCode() throws Exception {
        assertEquals(JANUARY, stringToMonthCode("1"));
        assertEquals(FEBRUARY, stringToMonthCode("2"));
        assertEquals(MARCH, stringToMonthCode("3"));
        assertEquals(APRIL, stringToMonthCode("4"));
        assertEquals(MAY, stringToMonthCode("5"));
        assertEquals(JUNE, stringToMonthCode("6"));
        assertEquals(JULY, stringToMonthCode("7"));
        assertEquals(AUGUST, stringToMonthCode("8"));
        assertEquals(SEPTEMBER, stringToMonthCode("9"));
        assertEquals(OCTOBER, stringToMonthCode("10"));
        assertEquals(NOVEMBER, stringToMonthCode("11"));
        assertEquals(DECEMBER, stringToMonthCode("12"));

        //todo assertEquals(-1, stringToMonthCode("0"));
        //assertEquals(13, stringToMonthCode("0"));

        assertEquals(-1, stringToMonthCode("Hello"));

        for (int m = 1; m <= 12; m++) {
            assertEquals(m, stringToMonthCode(monthCodeToString(m, false)));
            assertEquals(m, stringToMonthCode(monthCodeToString(m, true)));
        }

        assertEquals(1, stringToMonthCode("jan"));
    }

    public void testIsValidWeekInMonthCode() throws Exception {
        for (int w = 0; w <= 4; w++) {
            assertTrue(isValidWeekInMonthCode(w));
        }

        assertFalse(isValidWeekInMonthCode(5));
    }

    public void testIsLeapYear() throws Exception {
        assertFalse(isLeapYear(1900));
        assertFalse(isLeapYear(1901));
        assertFalse(isLeapYear(1902));
        assertFalse(isLeapYear(1903));
        assertTrue(isLeapYear(1904));
        assertTrue(isLeapYear(1908));
        assertFalse(isLeapYear(1955));
        assertTrue(isLeapYear(1964));
        assertTrue(isLeapYear(1980));
        assertTrue(isLeapYear(2000));
        assertFalse(isLeapYear(2001));
        assertFalse(isLeapYear(2100));
    }

    public void testLeapYearCount() throws Exception {
        assertEquals(0, leapYearCount(1900));
        assertEquals(0, leapYearCount(1901));
        assertEquals(0, leapYearCount(1902));
        assertEquals(0, leapYearCount(1903));
        assertEquals(1, leapYearCount(1904));
        assertEquals(2, leapYearCount(1908));
        assertEquals(24, leapYearCount(1999));
        assertEquals(25, leapYearCount(2001));
        assertEquals(49, leapYearCount(2101));
        assertEquals(73, leapYearCount(2201));
        assertEquals(97, leapYearCount(2301));
        assertEquals(122, leapYearCount(2401));
    }

    public void testLastDayOfMonth() throws Exception {
        assertEquals(31, lastDayOfMonth(JANUARY, 1901));
        assertEquals(28, lastDayOfMonth(FEBRUARY,1901));
        assertEquals(31, lastDayOfMonth(MARCH,1901));
        assertEquals(30, lastDayOfMonth(APRIL,1901));
        assertEquals(31, lastDayOfMonth(MAY,1901));
        assertEquals(30, lastDayOfMonth(JUNE,1901));
        assertEquals(31, lastDayOfMonth(JULY,1901));
        assertEquals(31, lastDayOfMonth(AUGUST,1901));
        assertEquals(30, lastDayOfMonth(SEPTEMBER,1901));
        assertEquals(31, lastDayOfMonth(OCTOBER,1901));
        assertEquals(30, lastDayOfMonth(NOVEMBER,1901));
        assertEquals(31, lastDayOfMonth(DECEMBER,1901));
        assertEquals(29, lastDayOfMonth(FEBRUARY,1904));
    }

    public void testAddDays() throws Exception {
        SerialDate newYears = d(1, JANUARY, 1900);
        assertEquals(d(2, JANUARY, 1900), addDays(1, newYears));
        assertEquals(d(1, FEBRUARY, 1900), addDays(31, newYears));
        assertEquals(d(1, JANUARY, 1901), addDays(365, newYears));
        assertEquals(d(31, DECEMBER, 1904), addDays(5 * 365, newYears));
    }

    private static SpreadsheetDate d(int day, int month, int year) {
        return new SpreadsheetDate(day, month, year);
    }
}