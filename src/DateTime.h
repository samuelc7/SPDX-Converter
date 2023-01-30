// DateTime
#ifndef DATE_TIME_H
#define DATE_TIME_H
#include <string>

class DateTime {
    private: 
        int year;
        int month; 
        int day;
        int hour;
        int min;
        int sec;
        /**
         * @brief Converts a string section of Date into an int
         * 
         * @param s - size (number of digits)
         * @param start - start index
         * @param end - end index
         * @param original - the string to be searched
         * @return int 
         */
        int convertToInt(int s, int start, int end, std::string original);
    public:
        // Constructors
        DateTime();
        DateTime(int y, int M, int d, int h, int m, int s);
        
        // Getters
        int getYear();
        int getMonth();
        int getDay();
        int getHour();
        int getMin();
        int getSec();

        // Setters
        void setYear(int y);
        void setMonth(int M);
        void setDay(int d);
        void setHour(int h);
        void setMin(int m);
        void setSec(int s);

        /**
         * @brief Parses strings in the format yyyy-MM-ddThh:mm:ssZ to DateTime objects
         * @param str - the date as a string in the format yyyy-MM-ddThh:mm:ssZ
         */
        void parseString(std::string str);

        //friend std::ostream& operator<<(std::ostream& os, DateTime& dt);
        
        std::string toString();
};

#endif