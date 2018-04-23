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
    static final int[] LEAP_YEAR_AGGREGATE_DAYS_TO_END_OF_MONTH =
            {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

}
