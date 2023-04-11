import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # obtain users entry
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        # execute entry via SQL query
        db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", name, month, day)

        # confirm entry
        return redirect("/")

    else:
        # obtain birthdays from db via SQL query
        birthdays = db.execute("SELECT * FROM birthdays")

        # return db
        return render_template("index.html", birthdays=birthdays)

@app.route("/deregister", methods=["POST"])
def deregister():

    # obtain id from button press
    id = request.form.get("id")
        if id:
            db.execute("DELETE FROM birthdays WHERE id = ?", id)

    # confirm deletion
    return redirect("/")

