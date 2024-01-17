package com.stegano.labs.lab1;

import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

public class UtilsLab1 {
    public static final Charset ENCODING = StandardCharsets.UTF_8;
    public static final int BIT_DEPTH = 16;

    public static final Character INSERT_CHAR = '\u00A0';
    public static final String END_SEQUENCE = "\u00A0\u00A0";
}
