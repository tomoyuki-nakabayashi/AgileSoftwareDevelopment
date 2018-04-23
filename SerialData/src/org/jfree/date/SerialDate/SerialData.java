package org.jfree.date.SerialDate;

import java.io.Serializable;
import java.text.DateFormatSymbols;
import java.text.SimpleDateFormat;
import java.util.Calendar;


public abstract class SerialData implements Comparable,
                                            Serializable,
                                            MonthConstants {

    private static final long serialVersionUID = -293716040467423637L;
    public static final DateFormatSymbols DATE_FORMAT_SYMBOLS =
            new SimpleDateFormat().getDateFormatSymbols();

    public static final int SERIAL_LOWER_BOUND = 2;
    public static final int SERIAL_UPPER_BOUND = 2958465;
    public static final int MINIMUM_YEAR_SUPPORTED = 1900;
    public static final int MAXIMUM_YEAR_SUPPORTED = 9999;

    public static final int MONDAY = Calendar.MONDAY;
    public static final int TUESDAY = Calendar.TUESDAY;
    public static final int WEDNESDAY = Calendar.WEDNESDAY;
    public static final int THURSDAY = Calendar.THURSDAY;
    public static final int FRIDAY = Calendar.FRIDAY;
    public static final int SATURDAY = Calendar.SATURDAY;
    public static final int SUNDAY = Calendar.SUNDAY;

    static final int[] LAST_DAY_OF_MONTH = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static final int[] AGGREGATE_DAYS_TO_END_OF_MONTH =
            {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    static final int[] AGGREGATE_DAYS_TO_END_OF_PRECEDING_MONTH =
            {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    static final int[] LEAP_YEAR_AGGREGATE_DAYS_TO_END_OF_MONTH =
            {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
    static final int[] LEAP_YEAR_AGGREGATE_DAYS_TO_END_OF_PRECEDING_MONTH =
            {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

    public static final int FIRST_WEEK_IN_MONTH = 1;
    public static final int SECOND_WEEK_IN_MONTH = 2;
    public static final int THIRD_WEEK_IN_MONTH = 3;
    public static final int FOURTH_WEEK_IN_MONTH = 4;
    public static final int LAST_WEEK_IN_MONTH = 0;

    public static final int INCLUDE_NONE = 0;
    public static final int INCLUDE_FIRST = 1;
    public static final int INCLUDE_SECOND = 2;
    public static final int INCLUDE_BOTH = 3;

    public static final int PRECEDING = -1;
    public static final int NEAREST = 0;
    public static final int FOLLOWING = 1;

    private String description;

    protectedSerialDate() {
    }

    public static boolean isValidWeekdayCode(final int code) {
        switch (code) {
            case SUNDAY:
            case MONDAY:
            case TUESDAY:
            case WEDNESDAY:
            case THURSDAY:
            case FRIDAY:
            case SATURDAY:
                return true;
            default:
                return false;
        }
    }

    public static int stringToWeekdayCode(String s) {
        final String[] shortWeekdayNames =
                DATE_FORMAT_SYMBOLS.getShortWeekdays();
        final String[] weekDayNames = DATE_FORMAT_SYMBOLS.getWeekdays();

        int result = -1;
        s = s.trim();
        for (int i = 0; i < weekDayNames.length; i++) {
            if (s.equals(shortWeekdayNames[i])) {
                result = i;
                break;
            }
            if (s.equals(weekDayNames[i])) {
                result = i;
                break;
            }
        }
        return result;
    }

    public static String weekdayCodeToString(final int weekday) {
        final String[] weekdays = DATE_FORMAT_SYMBOLS.getWeekdays();
        return weekdays[weekday];
    }

    public static String[] getMonths() {
        return getMonths(false);
    }

    public static String[] getMonths(final boolean shortened) {
        if (shortened) {
            return DATE_FORMAT_SYMBOLS.getShortMonths();
        } else {
            return DATE_FORMAT_SYMBOLS.getMonths();
        }
    }

    public static boolean isValidMonthCode(final int code) {
        switch (code) {
            case JANUARY:
            case FEBRUARY:
            case MARCH:
            case APRIL:
            case MAY:
            case JUNE:
            case JULY:
            case AUGUST:
            case SEPTEMBER:
            case OCTOBER:
            case NOVEMBER:
            case DECEMBER:
                return true;
            default:
                return false;
        }
    }

    public static int monthCodeToQuarter(final int code) {
        switch (code) {
            case JANUARY:
            case FEBRUARY:
            case MARCH: return 1;
            case APRIL:
            case MAY:
            case JUNE: return 2;
            case JULY:
            case AUGUST:
            case SEPTEMBER: return 3;
            case OCTOBER:
            case NOVEMBER:
            case DECEMBER: return 4;
            default:
                throw new IllegalArgumentException(
                        "SerialDate.monthCodeToQuarter: invalid month code."
                );
        }
    }

    public static String monthCodeToString(final int month) {
        return monthCodeToString(month, false);
    }

    public static String monthCodeToString(final int month, final boolean shortened) {
        if (!isValidMonthCode(month)) {
            throw new IllegalArgumentException(
                    "SerialDate.monthCodeToString: month outside valid range."
            );
        }

        final String[] months;
        if(shortened) {
            months = DATE_FORMAT_SYMBOLS.getShortMonths();
        } else {
            months = DATE_FORMAT_SYMBOLS.getMonths();
        }

        return months[month - 1];
    }

    public static int stringToMonthCode(String s) {
        final String[] shortMonthNames = DATE_FORMAT_SYMBOLS.getShortMonths();
        final String[] monthNames = DATE_FORMAT_SYMBOLS.getMonths();

        int result = -1;
        s = s.trim();

        try {
            result = Integer.parseInt(s);
        } catch (NumberFormatException e) {
            // suppress
        }

        if ((result < 1) || (result > 12)) {
            for (int i = 0; i < monthNames.length; i++) {
                if (s.equals(shortMonthNames[i])) {
                    result = i + 1;
                    break;
                }
                if (s.equals(monthNames[i])) {
                    result = i + 1;
                    break;
                }
            }
        }
        return result;
    }

    public static boolean isValidWeekInMonthCode(final int code) {
        switch(code) {
            case FIRST_WEEK_IN_MONTH:
            case SECOND_WEEK_IN_MONTH:
            case THIRD_WEEK_IN_MONTH:
            case FOURTH_WEEK_IN_MONTH:
            case LAST_WEEK_IN_MONTH: return true;
            default: return false;
        }
    }

    public static boolean isLeapYear(final int yyyy) {
        if ((yyyy % 4 != 0)) {
            return false;
        }
        else if ((yyyy % 400 == 0)) {
            return true;
        } else if ((yyyy % 100) == 0) {
            return false;
        } else {
            return true;
        }
    }

    public static int leapYearCount(final int yyyy) {
        final int leap4 = (yyyy - 1896) / 4;
        final int leap100 = (yyyy - 1800) / 100;
        final int leap400 = (yyyy - 1600) / 400;
        return leap4 - leap100 + leap400;
    }

    public static int lastDayOfMonth(final int month, final int yyyy) {
        final int result = LAST_DAY_OF_MONTH[month];
        if (month != FEBRUARY) {
            return result;
        }
        else if (isLeapYear(yyyy)) {
            return result + 1;
        } else {
            return result;
        }
    }
}

