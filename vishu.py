import mysql.connector as sq

def create():
    mydb = sq.connect(host="localhost",user="root",password="root")

    mycursor = mydb.cursor()

    sql = "Create database Power"

    mycursor.execute(sql)

    mycursor.execute("Use Power")
    
    mydb.commit()

    mycursor.execute("Create table Bill_System(Category VARCHAR(500), Sanctioned_load FLOAT, Supply_Type VARCHAR(500) , Reading_date DATE , Past_reading FLOAT , Present_reading FLOAT , Units_consumed FLOAT , Bill_Amount FLOAT)")

    mydb.commit()  

def check_database_existence():
    try:
        mydb = sq.connect(host="localhost",user="root",password="root",database="power")
    except sq.Error as e:
        if e.errno == 1049:  # MySQL error code for "Unknown database"
            create()
            print("Database created")
        else:
            print("Database already exists")
check_database_existence()

def insert():
    
    import mysql.connector as sq

    mydb = sq.connect(host="localhost",user="root",password="root",database="project")

    mycursor = mydb.cursor()
   
    sql = "INSERT INTO Anime (Category, Sanctioned_load, Supply_Type, Reading_date, Past_reading,Present_reading, Units_consumed, Bill_Amount) VALUES (%s, %s,%s,%s,%s,%s,%s,%s)"

    val = (Category, Sanctioned_load, Supply_Type, Reading_date, Past_reading,Present_reading, Units_consumed, Bill_Amount)

    mycursor.execute(sql, val)

    mydb.commit()

    print(mycursor.rowcount, "record inserted.")

def display():
        import mysql.connector as sq

        mydb = sq.connect(host="localhost",user="root",password="root",database="power")

        cursor = mydb.cursor()

        sql = "SELECT * FROM bill_system"

        cursor.execute(sql)
           
        myresult = cursor.fetchall()

        for x in myresult:

            print( x)

def delete():
        dele=input("Enter the record month you want to delete:")

        import mysql.connector as sq

        c=sq.connect(host="localhost",user="root",passwd="root",database="power")

        cursor=c.cursor()

        sql = "DELETE FROM bill_system WHERE MONTH(Reading_date) like '%{}%'".format(dele)

        cursor.execute(sql)

        c.commit()

        print("Record Deleted")

def update():
        up=input("Enter the month whose units you want to modify: ")
        
        change=input("Enter the new data: ")

        import mysql.connector as sq

        mydb= sq.connect(host="localhost",user="root",passwd="root",database="power")

        cursor=mydb.cursor()

        if up=="January":
            month=1
        elif up=="February":
            month=2
        elif up=="March":
            month=3
        elif up=="April":
            month=4
        elif up=="May":
            month=5
        elif up=="June":
            month=6
        elif up=="July":
            month=7
        elif up=="August":
            month=8
        elif up=="September":
            month=9
        elif up=="October":
            month=10
        elif up=="November":
            month=11
        elif up=="Decmber":
            month=12
        update="UPDATE bill_system set Units_consumed = {} WHERE MONTH(Reading_date) like '%{}%'".format(Change,month)

        cursor.execute(update)

        mydb.commit()

        print("Record Updated")
