# Use the official Node.js image from Docker Hub
FROM node:18-alpine

# Set the working directory inside the container
WORKDIR /app

# Step 1: Copy the package.json and package-lock.json (if available)
COPY ./Frontend/package*.json ./

# Step 2: Install the Node.js dependencies (fresh, matching container's OS/arch)
RUN npm install --omit=dev

# Step 3: Copy the rest of the application code to the container
# (Frontend/node_modules is excluded via .dockerignore)
COPY ./Frontend .

# Expose the port that your Node.js app runs on
EXPOSE 3000

# Step 4: Command to start the Node.js application
CMD ["node", "server.js"]

